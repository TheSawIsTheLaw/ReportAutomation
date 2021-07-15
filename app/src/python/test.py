# That's a script, okey? That's why we use some fucking shitty decisions.
import sys
from openpyxl import load_workbook
import codecs


def getRulesFromConfig(configPath):
    outRules = dict()

    with open(configPath, encoding = 'utf-8') as file:
        lines = file.readlines()

    for curLine in lines:
        threeFirstChars = curLine[:-3]
        if threeFirstChars == "!--":
            continue
        # Тут потребуется декомпозировать на отдельные функции. При нахождении определённого
        # раздела конфига - ищем конец раздела и передаём строки в функцию на проверку
        elif threeFirstChars ==

    print(lines)

    return outRules

'''
    REALLY FUCKING IMPORTANT!!!
    We have a small trouble using some names with spaces. That's why
    we MUST send ways in quotes like 'C:/Go Fuck Yourself/Program Files/fuck fuck fuck fuck'
    Why can't we use '_'? BECAUSE OF FUCKING 'FUCK:/GO_FUCK/FUCKING_FUCK/FUCK FUCK FUCK'
    
    I think you've got it, right?
'''
### REALLY IMPORTANT:
def main():
    gotArgs = sys.argv

    tablePath = sys.argv[1]         # path to table to get info from
    docSavePath = sys.argv[2]       # path to save document
    configPath = sys.argv[3]        # path to configuration
    workRowNumber = sys.argv[4]     # number of row from table

    dictOfRulesForDoc = getRulesFromConfig(configPath)

    return 0

main()
