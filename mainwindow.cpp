#include "mainwindow.h"
#include <picker_random.h>
#include "ui_mainwindow.h"

#include <QMessageBox>

#include <fstream>
#include <random>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	ui->mainLayout->setAlignment(ui->startButton, Qt::AlignHCenter);
	ui->mainLayout->setAlignment(ui->randomTypeBox, Qt::AlignHCenter);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::on_fileNameEdit_returnPressed() {
	std::ifstream ifs(ui->fileNameEdit->text().toStdString());
	if(ifs.good()) {
		while(ifs.good()) {
			std::string str;
			std::getline(ifs, str);
			entries.push_back(str);
			ui->entryList->addItem(QString::fromStdString(str));
		}
	}
	else {
		QMessageBox box;
		box.setText("Couldn't find the file");
		box.exec();
	}
}

void MainWindow::on_entryEdit_returnPressed() {
	ui->entryList->addItem(ui->entryEdit->text());
	entries.push_back(ui->entryEdit->text().toStdString());
	ui->entryEdit->clear();
}

void MainWindow::on_startButton_clicked() {
	picker::RandomMethod method;
	std::string checked = ui->buttonGroup->checkedButton()->objectName().toStdString();
	if("randomOrgRadio" == checked)
		method = picker::RandomMethod::RANDOM_ORG;
	else if("mersenneRadio" == checked) {
		method = picker::RandomMethod::MERSENNE;
		std::shuffle(entries.begin(), entries.end(), picker::seededEngine());
		repopulateList();
	}
	//TODO separate calling shuffle
	//picker::rearrange(entries.begin(), entries.end(), method);
}

void MainWindow::on_eraseListButton_clicked() {
	ui->entryList->clear();
	entries.clear();
}
void MainWindow::repopulateList() {
	ui->entryList->clear();
	for(std::string s : entries) ui->entryList->addItem(QString::fromStdString(s));
}
