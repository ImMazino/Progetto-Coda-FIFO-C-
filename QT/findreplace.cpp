#include "findreplace.h"
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QTextDocument>

FindReplace::FindReplace(QTextEdit *editor, QWidget *parent)
    : QDialog(parent), editor(editor) {
    setWindowTitle("Trova e Sostituisci");

    findLine = new QLineEdit(this);
    replaceLine = new QLineEdit(this);
    caseSensitive = new QCheckBox("Case sensitive", this);
    wholeWord = new QCheckBox("Trova parola intera", this);
    QPushButton *findButton = new QPushButton("Trova", this);
    QPushButton *replaceButton = new QPushButton("Sostituisci", this);
    QPushButton *replaceAllButton = new QPushButton("Sostituisci tutto", this);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(findLine);
    layout->addWidget(replaceLine);
    layout->addWidget(caseSensitive);
    layout->addWidget(wholeWord);
    layout->addWidget(findButton);
    layout->addWidget(replaceButton);
    layout->addWidget(replaceAllButton);
    setLayout(layout);

    connect(findButton, &QPushButton::clicked, this, &FindReplace::Find);
    connect(replaceButton, &QPushButton::clicked, this, &FindReplace::Replace);
    connect(replaceAllButton, &QPushButton::clicked, this, &FindReplace::findAndReplace);
}


//Metodo per la ricerca del testo nell'editor
//Scorre il testo evidenziando il testo trovato
//Rispetta i paramentri FindCaseSensitively e FindWholeWords se la checkbox è true
void FindReplace::Find() {
    QString findText = findLine->text();

    if (findText.isEmpty()){
        return;
    }

    QTextDocument::FindFlags flags;
    if (caseSensitive->isChecked()){
        flags |= QTextDocument::FindCaseSensitively;
    }
    if (wholeWord->isChecked()){
        flags |= QTextDocument::FindWholeWords;
    }

    if(!editor->find(findText, flags)){
        editor->moveCursor(QTextCursor::Start);
        editor->find(findText, flags);
    }
}

//Metodo per la sostituzione del testo nell'editor
//Scorre il testo sostiduendo le parole evidenziate con il nuovo testo
void FindReplace::Replace() {
    QString findText = findLine->text();
    QString replaceText = replaceLine->text();

    QTextCursor cursor = editor->textCursor();

    if(cursor.selectedText() == findText){
        cursor.insertText(replaceText);
    }
}

//Metodo per la ricerca e sostituzione del testo nell'editor
//Scorre il testo e sostituisce tutte le parole che rispettano i parametri
void FindReplace::findAndReplace() {
    QString findText = findLine->text();
    QString replaceText = replaceLine->text();

    if (findText.isEmpty() || findText == replaceText){
        return;
    }

    QTextDocument::FindFlags flags;
    if (caseSensitive->isChecked()){
        flags |= QTextDocument::FindCaseSensitively;
    }
    if (wholeWord->isChecked()){
        flags |= QTextDocument::FindWholeWords;
    }

    editor->moveCursor(QTextCursor::Start);

    while (editor->find(findText, flags)){
        QTextCursor cursor = editor->textCursor();
        cursor.insertText(replaceText);
        editor->setTextCursor(cursor);
    }

    editor->moveCursor(QTextCursor::Start);
}


