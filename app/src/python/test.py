# That's a script, okey? That's why we use some fucking shitty decisions.
import sys
from openpyxl import load_workbook
import codecs


# https://stackoverflow.com/questions/55115070/next-letter-in-alphabet
def nextAlphabetLetter(s):
    return chr((ord(s.upper()) + 1 - 65) % 26 + 65)


def throwWrongStructure():
    raise Exception("Конфигурационный файл не соответствует требуемому формату")


# fTest: python test.py a a C:\Users\dobri\Desktop\ReportAutomation\app\src\config\stdConfig.ycfg 1
def goToNextSharps(lines, curLineNumber):
    while curLineNumber < len(lines):
        if lines[curLineNumber][:3] == "###":
            return curLineNumber
        curLineNumber += 1
    return -1


'''
    Function forms rules in a dictionary for the next step (excel table processing)
    
    Forms a dictionary with fields: startOfTable, headers.
    --- startOfTable contains two ints which are coordinates of start of table (vertical and then horizontal)
    --- headers contains two strings: format of field, it's horizontal letter (coordinate in excel lol ok)
'''


def getRulesFromConfig(configPath):
    outRules = dict()

    with open(configPath, encoding = 'utf-8') as file:
        lines = file.readlines()

    # Search of table start coordinates
    curLineNumber = goToNextSharps(lines, 0)
    # print(lines[curLineNumber].replace(" \n\0", ""))
    if lines[curLineNumber] != "### Область названий организаций\n":
        throwWrongStructure()

    curLineNumber += 1
    outRules["startOfTable"] = lines[curLineNumber].split(" ")
    outRules["startOfTable"] = map(lambda curNum: int(curNum), outRules["startOfTable"])

    #    for i in outRules["startOfTable"]:
    #        print("!!{}".format(i))

    # Search of headers in configFile
    curLineNumber = goToNextSharps(lines, curLineNumber)
    curLineNumber += 1
    if curLineNumber == len(lines):
        throwWrongStructure()

    headersInDocument = []
    curHeaderDescription = lines[curLineNumber]
    while curLineNumber < len(lines) - 1 and curHeaderDescription[0] == "[":
        curHeaderDescription = curHeaderDescription.replace("\n", "").split(" ")
        headersInDocument.append(curHeaderDescription)

        curLineNumber += 1
        curHeaderDescription = lines[curLineNumber]

    outRules["headers"] = headersInDocument

    return outRules


'''
    REALLY FUCKING IMPORTANT!!!
    We have a small trouble using some names with spaces. That's why
    we MUST send ways in quotes like 'C:/Go Fuck Yourself/Program Files/fuck fuck fuck fuck'
    Why can't we use '_'? BECAUSE OF FUCKING 'FUCK:/GO_FUCK/FUCKING_FUCK/FUCK FUCK FUCK'
    
    I think you've got it, right?
'''


def main():
    gotArgs = sys.argv

    try:
        tablePath = sys.argv[1]  # path to table to get info from
        docSavePath = sys.argv[2]  # path to save document
        configPath = sys.argv[3]  # path to configuration
        workRowNumber = int(sys.argv[4])  # number of row from table
    except:
        return 1

    dictOfRulesForDoc = getRulesFromConfig(configPath)

    return 0


ret = main()
if not ret:
    print("OK")
else:
    print("err")
