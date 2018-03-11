#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	ui->mainLayout->setAlignment(ui->startButton, Qt::AlignHCenter);
	ui->mainLayout->setAlignment(ui->randomTypeBox, Qt::AlignHCenter);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_entryEdit_returnPressed() {
	ui->entryList->addItem(ui->entryEdit->text());
	entries.push_back(ui->entryEdit->text().toStdString());
	ui->entryEdit->clear();
}

void MainWindow::on_startButton_clicked() {

}

void MainWindow::on_eraseListButton_clicked() {
	ui->entryList->clear();
	entries.clear();
}
