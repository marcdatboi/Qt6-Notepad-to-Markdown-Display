



#include "MarkdownEditor.hpp"
#include <QHBoxLayout>
#include <QGuiApplication>
#include <QScreen>

MarkdownEditor::MarkdownEditor(QWidget *parent)
    : QWidget(parent)
    , parentWidget(parent)
{
    setupWidget();
    /**
     * Enter constructor code here!
     */
}
MarkdownEditor::~MarkdownEditor(){}

QPlainTextEdit* MarkdownEditor::getTextEditor() { return this->textEditor; }

void MarkdownEditor::setupWidget()
{
    // 1. Initialize the QPlainTextEdit and set the placeholder text
    this->textEditor = new QPlainTextEdit(this);
    this->textEditor->setPlaceholderText("Enter Text Here...");

    // 2. Set up the layout to make the text editor fill this widget completely
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(textEditor);
    mainLayout->setContentsMargins(0, 0, 0, 0); // Remove margins so it takes full widget space
    this->setLayout(mainLayout);

    // 3. Handle the initial sizing (Half width, full height of the primary screen/window)
    QSize applicationWindowSize = this->parentWidget->size();
    int applicationWidth = applicationWindowSize.width();
    this->setFixedWidth(applicationWidth / 2);

    // 4. Set a size policy so it behaves nicely if put into a layout later
    setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
}

