#ifndef FINDREPLACE_H
#define FINDREPLACE_H

#include <QDialog>
#include <QTextEdit>

class QLineEdit;
class QCheckBox;

class FindReplace : public QDialog {
    Q_OBJECT

public:
    FindReplace(QTextEdit *editor, QWidget *parent = nullptr);

private slots:
    void Find();
    void Replace();
    void findAndReplace();

private:
    QTextEdit *editor;
    QLineEdit *findLine;
    QLineEdit *replaceLine;
    QCheckBox *caseSensitive;
    QCheckBox *wholeWord;
};

#endif
