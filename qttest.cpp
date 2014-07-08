#include "qttest.h"
#include "ui_qttest.h"

#include <iostream>

#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QTextStream>
#include <QTextCursor>
#include <QMessageBox>

#include "aboutbox.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    lastDir("/")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mbAbout_triggered()
{
    // show AboutBox as modal dialg
    AboutBox aboutBox;
    aboutBox.setModal(true);
    aboutBox.exec();
}

void MainWindow::on_mbOpenFile_triggered()
{
    // get file name from user
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), lastDir);
    if(!fileName.isNull()){
        QFileInfo fileInfo(fileName);
        lastDir = fileInfo.absolutePath();
        if(fileInfo.isReadable()){
            // read file contents
            QFile file(fileName);
            file.open(QIODevice::ReadOnly);
            QTextStream textStream(&file);
            QString text = textStream.readAll();
            // fill text-field and set cursor to beginning
            ui->textEdit->setPlainText(text);
            QTextCursor cursor = ui ->textEdit->textCursor();
            cursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor, 1);
        }else{
            // file not readable => show error-message-box
            QMessageBox::critical(0, tr("File not readable"), tr("The file, you have choosen, is not readable and thus, cannot be opened."), QMessageBox::Close);
        }
    }
}
