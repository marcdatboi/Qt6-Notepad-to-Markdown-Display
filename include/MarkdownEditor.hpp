



#include <QPlainTextEdit>

class MarkdownEditor : public QWidget
{
    Q_OBJECT

public:
    MarkdownEditor(QWidget *parent = nullptr);
    ~MarkdownEditor();

    // Functions :P
    QPlainTextEdit* getTextEditor();

private:
    QWidget *parentWidget;
    QPlainTextEdit *textEditor;
    void setupWidget();
};