from PyQt5.QtCore import *
from PyQt5.QtWidgets import *
import sys


class ChildWindow(QDialog):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.setWindowFlags(Qt.WindowCloseButtonHint)
        self.setWindowTitle('New Window')
        self.resize(250, 180)


class FatherWindow(QWidget):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        # Set the window title and size
        self.setWindowTitle('TestWindow')
        self.resize(400, 350)

        self.btn = QPushButton('Open a new window', self)

        self.btn.clicked.connect(self.btnClicked)
        self.btn.move(80, 80)

        self.show()


    def btnClicked(self):
        self.chile_Win = ChildWindow()
        self.chile_Win.move(self.x() + self.btn.geometry().x() + 1,
                        self.y() + self.btn.geometry().y() + self.btn.height() + 35)
        self.chile_Win.show()
        self.chile_Win.exec_()


if __name__ == '__main__':
    # Create application
    app = QApplication(sys.argv)
    # Create main window
    window = FatherWindow()
    # Display window
    window.show()
    # Run the application and listen for events
    sys.exit(app.exec_())