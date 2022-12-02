#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <vector>
#include <string>
#include <QFile>
#include <QMessageBox>
#include <algorithm>
#include <QColorDialog>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void process_langs();
    void keyPressEvent(QKeyEvent *k);

private slots:
    void on_exit_button_clicked();

    void on_search_button_clicked();

    void on_clearButton_clicked();

    void on_info_clicked();

    void on_dark_mode_clicked();

    void on_light_mode_clicked();

    void on_info_2_clicked();

    void on_change_color_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

    void on_text_clear_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
