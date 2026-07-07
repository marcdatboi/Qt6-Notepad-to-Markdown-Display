



#include <QLabel>
#include "MainWindow.hpp"
#include "MarkdownEditor.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setupWindow();

    MarkdownEditor *editor = new MarkdownEditor(this);
    this->centralLayout->addWidget(editor);


    // --- Markdown Display Window ---
    QLabel *markdownDisplay = new QLabel("Markdown Text Will Appear Here...", this);

    // Getting font
    QFont labelFont = markdownDisplay->font();
    int pointSize = labelFont.pointSize();

    // Initialize starting state of the markdown display
    markdownDisplay->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    markdownDisplay->setStyleSheet(QString("QLabel { "
                                           "font-size: %1px;"
                                           "background-color: #222021;"
                                           "border: 2px solid #73c2fb;"
                                           "border-radius: 5px;"
                                           "}")
                                           .arg(pointSize * 2));

    // Add to layout
    this->centralLayout->addWidget(markdownDisplay);

    // Making behavior
    connect(editor->getTextEditor(), &QPlainTextEdit::textChanged, [=]()
    {
        markdownDisplay->setTextFormat(Qt::MarkdownText);
        markdownDisplay->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        markdownDisplay->setText(editor->getTextEditor()->toPlainText());
        markdownDisplay->setStyleSheet(QString("QLabel { "
                                           "font-size: %1px;"
                                           "background-color: #222021;"
                                           "border: 2px solid #73c2fb;"
                                           "border-radius: 5px;"
                                           "}")
                                           .arg(pointSize * 2));
    });
}

MainWindow::~MainWindow() {}

void MainWindow::setupWindow()
{
    // Set the window title and default size
    this->setWindowTitle("Markdown Text Editor");
    this->resize(800, 600);

    // Initialize the central widget
    this->centralWidget = new QWidget(this);
    this->centralWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setCentralWidget(centralWidget);

    // Initialize the main vertical layout and assign it to the central widget
    this->centralLayout = new QHBoxLayout(centralWidget);
    this->centralWidget->setLayout(this->centralLayout);
}