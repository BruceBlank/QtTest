#ifndef QTTEST_H
#define QTTEST_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    // MenuBar "About" clicked (will be automatically connected, because of its name)
    void on_mbAbout_triggered();
    // MenuBar "OpenFile" clicked (will be automatically connected, because of its name)
    void on_mbOpenFile_triggered();

private:
    Ui::MainWindow *ui;
    QString lastDir;
};

#endif // QTTEST_H
