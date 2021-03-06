#include "Parser.h"

Parser::Parser(ISource* source) : _source(source)
{
}

Parser::~Parser()
{
}

void Parser::parse(IVisitor* visitor)
{
    string inputString;
    _source->read(inputString);

    if (inputString.size() == 0)
    {
        std::cout << "Empty string" << std::endl;
        return;
    }

    if (inputString.substr(0, 3) != "---")
    {
        std::cout << "This is not YAML" << std::endl;
        return;
    }

    if (inputString.find(':') == std::string::npos)
    {
        std::cout << "YAML is empty" << std::endl;
        return;
    }

    int spaceNotificator = 0;
    int spaceCounter = 0;
    int startString = 0;
    int nestCounter = 0;

    bool isCurrentNodeParent = true;

    int i = 3;
    for (i; i < inputString.size(); i++)
    {
        if (isspace(inputString[i]))
        {
            spaceNotificator = i;
            spaceCounter++;

            nestCounter = spaceCounter / 2;
        }

        if (inputString[i] == ':')
        {
            std::string key = inputString.substr(spaceNotificator + 1, i - spaceNotificator - 1);
            visitor->onParseKey(key, nestCounter);

            isCurrentNodeParent = true;
            spaceCounter = 0;

            if (inputString[i + 2] == 't')
            {
                // baseYamlObj->value = "true";
                i = i + 3;
                std::string tr = "true";
                visitor->onParseBool(tr);
                isCurrentNodeParent = false;
            }
            else if (inputString[i + 2] == 'f')
            {
                // baseYamlObj->value = "false";
                i = i + 4;
                std::string fl = "false";
                visitor->onParseBool(fl);
                isCurrentNodeParent = false;
            }


            continue;
        }

        if (inputString[i] == '"')
        {
            std::string str;
            int j = 0;

            while (inputString[i + 1] != '"')
            {
                str = str + inputString[i];
                i++;
                j++;
            }
            str = str + inputString[i] + '"';

            i++;
            std::pair<std::string, int> tmpPair = visitor->onParseStr(str);

            isCurrentNodeParent = false;
            spaceCounter = 0;
            continue;
        }

        if (isdigit(inputString[i]))
        {
            std::string number;
            int j = 0;
            while (i < inputString.size())
            {
                if (isspace(inputString[i]))
                {
                    // TODO: Infinity cycle if no space after number
                    break;
                }
                number = number + inputString[i];
                i++;
                j++;
            }
            visitor->onParseNumber(number);
            i--;

            isCurrentNodeParent = false;
            spaceCounter = 0;
            continue;
        }

        if (inputString[i] == '-')
        {
            int numberOfMembersInList = 0;
            int colonPos = 0;
            int startList = i;
            i = startList;
            bool isListAtEndOfFile = true;
            for (i; i < inputString.size(); i++)
            {
                if (inputString[i] == ':')
                {
                    colonPos = i;
                    isListAtEndOfFile = false;
                    break;
                }
            }

            // TODO: Maybe don't need to know numberOfMembersInList
            i = startList;
            if (isListAtEndOfFile)
            {
                for (i; i < inputString.size(); i++)
                {
                    if (inputString[i] == '-')
                    {
                        numberOfMembersInList++;
                    }
                }
            }
            else
            {
                for (i; i < colonPos; i++)
                {
                    if (inputString[i] == '-')
                    {
                        numberOfMembersInList++;
                    }
                }
            }

            std::string outAllList;
            std::vector<std::string> listMembers;
            std::string tempStr;

            int numberInList = 1;
            i = startList + 1;
            int spasesCounter = 0;
            for (i; i < inputString.size(); i++)
            {
                if (inputString[i] == '-')
                {
                    listMembers.push_back(tempStr);
                    tempStr.clear();
                    numberInList++;
                    continue;
                }

                if (!isspace(inputString[i]))
                {
                    tempStr = tempStr + inputString[i];
                }

                if ((numberInList == numberOfMembersInList) && isspace(inputString[i]))
                {
                    spasesCounter++;
                    if (spasesCounter > 1) {
                        break;
                    }

                }
            }
            listMembers.push_back(tempStr);

            for (int k = 0; k < listMembers.size(); k++)
            {
                outAllList += "- " + listMembers[k] + " ";
            }

            spaceNotificator = i;

            visitor->onParseList(outAllList);

            isCurrentNodeParent = false;
            spaceCounter = 0;
            continue;
        }


        // YAMLobj* currentYamlObj = (YAMLobj*)malloc(sizeof(YAMLobj));
        // baseYamlObj = currentYamlObj;
    }
    if (i != inputString.size())
    {
        return;
    }

    visitor->onFinished();

    return;
}
