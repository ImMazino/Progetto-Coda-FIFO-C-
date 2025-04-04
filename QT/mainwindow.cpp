#include "mainwindow.h"
#include "findreplace.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), textEdit(new QTextEdit(this)) {
    setCentralWidget(textEdit);
    setWindowTitle("Text Editor");
    setupMenu();
}

MainWindow::~MainWindow() {}

//Metodo che crea il menu bar
void MainWindow::setupMenu() {
    //menu a tendina
    QMenu *fileMenu = menuBar()->addMenu("File");
    //bottoni collegati ai metodi
    fileMenu->addAction("Nuovo", this, &MainWindow::newFile);
    fileMenu->addAction("Apri...", this, &MainWindow::openFile);
    fileMenu->addAction("Salva", this, &MainWindow::saveFile);
    fileMenu->addAction("Salva con nome...", this, &MainWindow::saveFileAs);

    menuBar()->addAction("Cerca", this, &MainWindow::openFindReplace);
}

//Metodo che fa il clear dell'editor
void MainWindow::newFile() {
    textEdit->clear();
    currentFilePath.clear();
}

//Metodo per aprire file di solo tipi .txt e .md
void MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Apri file", "", "File di testo (*.txt *.md)");
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QFile::ReadOnly | QFile::Text)) {
            QTextStream in(&file);
            textEdit->setPlainText(in.readAll());
            file.close();
            currentFilePath = fileName;
        }
    }
}

//Metodo per salvare il file
//Se il file non è mai stato salvato, passa al metodo saveFileAs()
void MainWindow::saveFile() {
    if (currentFilePath.isEmpty()) {
        saveFileAs();
        return;
    }
    else{
        QFile file(currentFilePath);
        if (file.open(QFile::WriteOnly | QFile::Text)) {
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        }
    }
}

//Metodo per salvare in nuovo file scelto dall'utente
void MainWindow::saveFileAs() {
    QString fileName = QFileDialog::getSaveFileName(this, "Salva file con nome", "", "File di testo (*.txt *.md)");
    if (!fileName.isEmpty()) {
        currentFilePath = fileName;
        saveFile();
    }
}

//Metodo per la sostizione
void MainWindow::openFindReplace() {
    FindReplace dialog(textEdit, this);
    dialog.exec();
}
