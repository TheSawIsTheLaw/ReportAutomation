# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'form.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, mainWindow):
        mainWindow.setObjectName("mainWindow")
        mainWindow.setWindowModality(QtCore.Qt.NonModal)
        mainWindow.resize(941, 602)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(mainWindow.sizePolicy().hasHeightForWidth())
        mainWindow.setSizePolicy(sizePolicy)
        self.gridLayout_2 = QtWidgets.QGridLayout(mainWindow)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.GridLay = QtWidgets.QGridLayout()
        self.GridLay.setSizeConstraint(QtWidgets.QLayout.SetDefaultConstraint)
        self.GridLay.setContentsMargins(0, -1, -1, -1)
        self.GridLay.setObjectName("GridLay")
        self.WaitingLabel = QtWidgets.QLabel(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.WaitingLabel.setFont(font)
        self.WaitingLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.WaitingLabel.setObjectName("WaitingLabel")
        self.GridLay.addWidget(self.WaitingLabel, 7, 0, 1, 2)
        self.LoadNewConfigButton = QtWidgets.QPushButton(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.LoadNewConfigButton.setFont(font)
        self.LoadNewConfigButton.setObjectName("LoadNewConfigButton")
        self.GridLay.addWidget(self.LoadNewConfigButton, 2, 0, 1, 2)
        self.MakeReportButton = QtWidgets.QPushButton(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.MakeReportButton.setFont(font)
        self.MakeReportButton.setObjectName("MakeReportButton")
        self.GridLay.addWidget(self.MakeReportButton, 6, 0, 1, 2)
        self.NameLabel = QtWidgets.QLabel(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.NameLabel.setFont(font)
        self.NameLabel.setLayoutDirection(QtCore.Qt.RightToLeft)
        self.NameLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.NameLabel.setObjectName("NameLabel")
        self.GridLay.addWidget(self.NameLabel, 1, 0, 1, 2)
        self.PathStatusLabel = QtWidgets.QLabel(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setItalic(False)
        font.setUnderline(False)
        font.setWeight(75)
        self.PathStatusLabel.setFont(font)
        self.PathStatusLabel.setAlignment(QtCore.Qt.AlignCenter)
        self.PathStatusLabel.setObjectName("PathStatusLabel")
        self.GridLay.addWidget(self.PathStatusLabel, 3, 1, 1, 1)
        self.NameOfFileLabel = QtWidgets.QLabel(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.NameOfFileLabel.setFont(font)
        self.NameOfFileLabel.setObjectName("NameOfFileLabel")
        self.GridLay.addWidget(self.NameOfFileLabel, 4, 1, 1, 1)
        self.SetSavePathButton = QtWidgets.QPushButton(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.SetSavePathButton.setFont(font)
        self.SetSavePathButton.setObjectName("SetSavePathButton")
        self.GridLay.addWidget(self.SetSavePathButton, 3, 0, 1, 1)
        self.NameOfFileInput = QtWidgets.QLineEdit(mainWindow)
        font = QtGui.QFont()
        font.setFamily("Bahnschrift SemiBold")
        font.setPointSize(16)
        font.setBold(True)
        font.setWeight(75)
        self.NameOfFileInput.setFont(font)
        self.NameOfFileInput.setInputMask("")
        self.NameOfFileInput.setText("")
        self.NameOfFileInput.setObjectName("NameOfFileInput")
        self.GridLay.addWidget(self.NameOfFileInput, 4, 0, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(5, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Fixed)
        self.GridLay.addItem(spacerItem, 5, 0, 1, 2)
        self.gridLayout_2.addLayout(self.GridLay, 0, 0, 1, 1)

        self.retranslateUi(mainWindow)
        QtCore.QMetaObject.connectSlotsByName(mainWindow)

    def retranslateUi(self, mainWindow):
        _translate = QtCore.QCoreApplication.translate
        mainWindow.setWindowTitle(_translate("mainWindow", "mainWin"))
        self.WaitingLabel.setText(_translate("mainWindow", "Ожидание действий от пользователя"))
        self.LoadNewConfigButton.setText(_translate("mainWindow", "Загрузить новую конфигурацию"))
        self.MakeReportButton.setText(_translate("mainWindow", "Исполнить предначертанное"))
        self.NameLabel.setText(_translate("mainWindow", "Автоматизированное создание отчётов (ну почти)"))
        self.PathStatusLabel.setText(_translate("mainWindow", "Путь не задан"))
        self.NameOfFileLabel.setText(_translate("mainWindow", "Имя нового файла (без расширения)"))
        self.SetSavePathButton.setText(_translate("mainWindow", "Задать путь сохранения"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    mainWindow = QtWidgets.QWidget()
    ui = Ui_MainWindow()
    ui.setupUi(mainWindow)
    mainWindow.show()
    sys.exit(app.exec_())
