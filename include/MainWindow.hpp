



#include <QMainWindow>
#include <QHBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *centralWidget;
    QHBoxLayout *centralLayout;

    // Set up starting state of the main window
    void setupWindow();
};