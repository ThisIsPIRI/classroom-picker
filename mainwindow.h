#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <string>
#include <vector>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

private slots:
	void on_entryEdit_returnPressed();
	void on_startButton_clicked();
	void on_eraseListButton_clicked();

private:
	Ui::MainWindow *ui;
	std::vector<std::string> entries;
};

#endif // MAINWINDOW_H
