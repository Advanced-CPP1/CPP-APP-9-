#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->description->hide();
    ui->light_mode->hide();
    ui->text_clear->hide();
    this->setWindowTitle("Code Snippets");
    this->setWindowIcon(QIcon(":/imgs/imgs/coder.ico"));
    this->setFixedSize(QSize(750, 500));
    this->setStyleSheet(QString("background-color: lightgreen;"));
    QFile file(":/imgs/imgs/bye.txt");
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly)) {
        return;
    }
    ui->lineEdit->setText(file.readAll());
    process_langs();
    ui->titleLabel->setText(QString("Code Snippet"));
    ui->titleLabel->setStyleSheet(QString("font-size: 16px;\n font-weight: bold;"));
    file.close();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::process_langs() {
    std::string lang = ui->lineEdit->text().toStdString();
    std::string buffer = lang;
    lang.erase(std::remove_if(lang.begin(), lang.end(), ::isspace), lang.end());
    std::transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
    buffer.erase(std::remove_if(buffer.begin(), buffer.end(), ::isspace), buffer.end());
    ui->lineEdit->setText(lang.c_str());
    if (buffer == "c++"){
          QPixmap cpp_logo(":/imgs/imgs/cpp_logo.png");
          QPixmap *cpp_pic1 = new QPixmap(":/imgs/imgs/cpp_pic1.png");
          QPixmap *cpp_pic2 = new QPixmap(":/imgs/imgs/cpp_pic2.png");
          QPixmap *cpp_pic3 = new QPixmap(":/imgs/imgs/cpp_pic3.png");
          QPixmap *cpp_pic4 = new QPixmap(":/imgs/imgs/cpp_pic4.png");
          QPixmap *cpp_pic5 = new QPixmap(":/imgs/imgs/cpp_pic5.png");
          QPixmap *cpp_pic6 = new QPixmap(":/imgs/imgs/cpp_pic6.png");
          QPixmap *cpp_pic7 = new QPixmap(":/imgs/imgs/cpp_pic7.png");
          std::vector<QPixmap *> cpp_pics {};
          ui->logo->setPixmap(cpp_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
          cpp_pics.push_back(cpp_pic1);
          cpp_pics.push_back(cpp_pic2);
          cpp_pics.push_back(cpp_pic3);
          cpp_pics.push_back(cpp_pic4);
          cpp_pics.push_back(cpp_pic5);
          cpp_pics.push_back(cpp_pic6);
          cpp_pics.push_back(cpp_pic7);
          srand(time(NULL));
          QPixmap *chosen_cpp = cpp_pics.at(rand() % cpp_pics.size());
          if (chosen_cpp == cpp_pic6)
              ui->image->setStyleSheet(QString("qproperty-alignment: AlignCenter;"));
          ui->image->setPixmap(chosen_cpp->scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
          delete cpp_pic1;
          delete cpp_pic2;
          delete cpp_pic3;
          delete cpp_pic4;
          delete cpp_pic5;
          delete cpp_pic6;
          delete cpp_pic7;
    }

    else if (buffer == "java") {
        QPixmap java_logo(":/imgs/imgs/java_logo.png");
        QPixmap *java_pic1 = new QPixmap(":/imgs/imgs/java_pic1.jpg");
        QPixmap *java_pic2 = new QPixmap(":/imgs/imgs/java_pic2.png");
        QPixmap *java_pic3 = new QPixmap(":/imgs/imgs/java_pic3.png");
        QPixmap *java_pic4 = new QPixmap(":/imgs/imgs/java_pic4.png");
        ui->logo->setPixmap(java_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        std::vector<QPixmap *> java_pics {};
        java_pics.push_back(java_pic1);
        java_pics.push_back(java_pic2);
        java_pics.push_back(java_pic3);
        java_pics.push_back(java_pic4);
        srand(time(NULL));
        QPixmap chosen_java = *(java_pics.at(rand() % java_pics.size()));
        ui->image->setPixmap(chosen_java.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
        delete java_pic1;
        delete java_pic2;
        delete java_pic3;
        delete java_pic4;
    }

    else if (buffer == "python") {
        QPixmap python_logo(":/imgs/imgs/python_logo.png");
        QPixmap *python_pic1 = new QPixmap(":/imgs/imgs/python_pic1.png");
        QPixmap *python_pic2 = new QPixmap(":/imgs/imgs/python_pic2.png");
        ui->logo->setPixmap(python_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        std::vector<QPixmap *> python_pics {} ;
        python_pics.push_back(python_pic1);
        python_pics.push_back(python_pic2);
        srand(time(NULL));
        QPixmap chosen_python = *(python_pics.at(rand() % python_pics.size()));
        ui->image->setPixmap(chosen_python.scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
        delete python_pic1;
        delete python_pic2;

    }

    else if (buffer == "rust") {
        QPixmap rust_logo(":/imgs/imgs/rust_logo.png");
        QPixmap *rust_pic1 = new QPixmap(":/imgs/imgs/rust_pic1.png");
        QPixmap *rust_pic2 = new QPixmap(":/imgs/imgs/rust_pic2.png");
        QPixmap *rust_pic3 = new QPixmap(":/imgs/imgs/rust_pic3.png");
        std::vector<QPixmap *> rust_pics {};
        rust_pics.push_back(rust_pic1);
        rust_pics.push_back(rust_pic2);
        rust_pics.push_back(rust_pic3);
        srand(time(NULL));
        QPixmap *chosen_rust = rust_pics.at(rand() % rust_pics.size());
        if (chosen_rust != rust_pic1) {
            ui->image->setStyleSheet(QString("qproperty-alignment: AlignCenter;"));
            ui->image->setPixmap(chosen_rust->scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
        }
        else
            ui->image->setPixmap(chosen_rust->scaled(ui->image->width(), ui->image->height()));
        ui->logo->setPixmap(rust_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        delete rust_pic1;
        delete rust_pic2;
        delete rust_pic3;
    }

    else if (buffer == "go" || buffer == "golang") {
        QPixmap go_logo(":/imgs/imgs/go_logo.png");
        QPixmap *go_pic1 = new QPixmap(":/imgs/imgs/go_pic1.png");
        ui->logo->setPixmap(go_logo.scaled(ui->logo->width(), ui->logo->height(), Qt::KeepAspectRatio));
        ui->image->setPixmap(go_pic1->scaled(ui->image->width(), ui->image->height(), Qt::KeepAspectRatio));
        delete go_pic1;
    }

    /* Separator */
    else {
        ui->titleLabel->clear();
        ui->image->setStyleSheet(QString("color: red;\n font-size: 20px;\n qproperty-alignment: AlignCenter;"));
        ui->image->setText(QString("Please enter a valid programming langauge"));
    }
}

void MainWindow::on_exit_button_clicked()
{
    QMessageBox msg;
    msg.setIcon(QMessageBox::Question);
    msg.setStandardButtons(QMessageBox::Yes| QMessageBox::No);
    msg.setWindowIcon(QIcon(":/imgs/imgs/exit_icon.ico"));
    msg.setWindowTitle(QString("Exit"));
    msg.setText(QString("Are you sure you want to exit?"));
    int ret = msg.exec();
    switch (ret) {
        case QMessageBox::Yes:
        this->close();
        break;
    }
}

void MainWindow::on_search_button_clicked()
{
    std::string buffer = ui->lineEdit->text().toStdString();
    buffer.at(0) = toupper(buffer.at(0));
    std::transform(buffer.begin() + 1, buffer.end(), buffer.begin() + 1, ::tolower);
    buffer.erase(std::remove_if(buffer.begin(), buffer.end(), ::isspace), buffer.end());
    ui->titleLabel->setText(QString("Code Snippet"));
    ui->titleLabel->setStyleSheet(QString("font-size: 16px;\n font-weight: bold;"));
    if (this->styleSheet() == QString("background-color: black;")) {
        ui->titleLabel->setStyleSheet(QString("color: yellow;\n font-weight: bold; font-size: 16px;"));
    }
    if (!ui->info->isVisible()) {
        ui->info->show();
    }
    ui->description->hide();
    process_langs();
    ui->lineEdit->setText(QString(buffer.c_str()));
    if (!ui->image->isVisible())
        ui->image->show();
}


void MainWindow::on_clearButton_clicked()
{
    ui->lineEdit->clear();
    ui->image->clear();
    ui->titleLabel->clear();
    ui->logo->clear();
    ui->description->clear();
    ui->info->hide();
    ui->info_2->hide();
    ui->text_clear->hide();
}

void MainWindow::on_info_clicked()
{
    ui->description->show();
    std::string lang_copy = ui->lineEdit->text().toStdString();
    std::transform(lang_copy.begin(), lang_copy.end(), lang_copy.begin(), ::tolower);
    lang_copy.erase(std::remove_if(lang_copy.begin(), lang_copy.end(), isspace), lang_copy.end());
    ui->info->hide();
    if (lang_copy == "c++")
        ui->description->setText(QString("C++ is a high-level general-purpose programming language created by Danish computer scientist Bjarne Stroustrup as an extension of the C programming language, or C with Classes. The language has expanded significantly over time, and modern C++ now has object-oriented, generic, and functional features in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM, so it is available on many platforms. C++ was designed with systems programming and embedded, resource-constrained software and large systems in mind, with performance, efficiency, and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, video games, servers (e.g. e-commerce, web search, or databases), and performance-critical applications (e.g. telephone switches or space probes)."));

    else if (lang_copy == "java")
        ui->description->setText(QString("Java is a high-level, class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible. It is a general-purpose programming language intended to let programmers write once, run anywhere (WORA), meaning that compiled Java code can run on all platforms that support Java without the need to recompile. Java applications are typically compiled to bytecode that can run on any Java virtual machine (JVM) regardless of the underlying computer architecture. The syntax of Java is similar to C and C++, but has fewer low-level facilities than either of them. The Java runtime provides dynamic capabilities (such as reflection and runtime code modification) that are typically not available in traditional compiled languages. As of 2019, Java was one of the most popular programming languages in use according to GitHub, particularly for client–server web applications, with a reported 9 million developers."));

    else if (lang_copy == "rust")
        ui->description->setText(QString("Rust is a multi-paradigm, general-purpose programming language. Rust emphasizes performance, type safety, and concurrency. Rust enforces memory safety—that is, that all references point to valid memory—without requiring the use of a garbage collector or reference counting present in other memory-safe languages.To simultaneously enforce memory safety and prevent concurrent data races, Rust's borrow checker tracks the object lifetime and variable scope of all references in a program during compilation. Rust is popular for systems programming but also offers high-level features including functional programming constructs. Software developer Graydon Hoare created Rust as a personal project while working at Mozilla Research in 2006. Mozilla officially sponsored the project in 2009. Rust's major influences include SML, OCaml, C++, Cyclone, Haskell, and Erlang. Since the first stable release in January 2014, Rust has been adopted by companies including Amazon, Discord, Dropbox, Facebook (Meta), Google (Alphabet), and Microsoft."));

    else if (lang_copy == "python")
        ui->description->setText(QString("Python is a high-level, general-purpose programming language. Its design philosophy emphasizes code readability with the use of significant indentation. Python is dynamically-typed and garbage-collected. It supports multiple programming paradigms, including structured (particularly procedural), object-oriented and functional programming. It is often described as a \"batteries included\" language due to its comprehensive standard library. Guido van Rossum began working on Python in the late 1980s as a successor to the ABC programming language and first released it in 1991 as Python 0.9.0. Python 2.0 was released in 2000 and introduced new features such as list comprehensions, cycle-detecting garbage collection, reference counting, and Unicode support. Python 3.0, released in 2008, was a major revision that is not completely backward-compatible with earlier versions. Python 2 was discontinued with version 2.7.18 in 2020. "));

    else if (lang_copy == "go" || lang_copy == "golang")
        ui->description->setText(QString("Go is a statically typed, compiled programming language designed at Google by Robert Griesemer, Rob Pike, and Ken Thompson. It is syntactically similar to C, but with memory safety, garbage collection, structural typing, and CSP-style concurrency. The Go language has built-in facilities, as well as library support, for writing concurrent programs. Concurrency refers not only to CPU parallelism, but also to asynchrony: letting slow operations like a database or network read run while the program does other work, as is common in event-based servers. The primary concurrency construct is the goroutine, a type of light-weight process. A function call prefixed with the go keyword starts a function in a new goroutine. The language specification does not specify how goroutines should be implemented, but current implementations multiplex a Go process's goroutines onto a smaller set of operating-system threads, similar to the scheduling performed in Erlang. While a standard library package featuring most of the classical concurrency control structures (mutex locks, etc.) is available, idiomatic concurrent programs instead prefer channels."));
    ui->info_2->show();
    ui->image->hide();
    ui->titleLabel->clear();
    ui->logo->hide();
    ui->description->setWordWrap(true);
}

void MainWindow::on_dark_mode_clicked()
{
    ui->titleLabel->setStyleSheet(QString("color: yellow;\n font-weight: 750;\n font-size: 16px;"));
    this->setStyleSheet(QString("background-color: black;"));
    ui->description->setStyleSheet(QString("color: white;\n font-weight: 750;\n font-size: 13px;"));
    ui->dark_mode->hide();
    ui->light_mode->show();
}

void MainWindow::on_light_mode_clicked() {
    this->setStyleSheet(QString("background-color: lightgreen;"));
    ui->description->setStyleSheet(QString("color: black;\n font-size: 13px;"));
    ui->titleLabel->setStyleSheet(QString("color: black;\n font-size: 16px;\n font-weight: bold;"));
    ui->light_mode->hide();
    ui->dark_mode->show();
}

void MainWindow::on_info_2_clicked()
{
    ui->info_2->hide();
    ui->titleLabel->setText(QString("Code Snippet"));
    ui->titleLabel->setStyleSheet(QString("font-weight: bold;\n font-size: 16px;"));
    if (this->styleSheet() == QString("background-color: black;")) {
        ui->titleLabel->setStyleSheet(QString("color: yellow;\n font-size: 16px;\n font-weight: bold;"));
        ui->description->setStyleSheet(QString("color: white;\n font-size: 13px;\n font-weight: bold;"));
    }
    ui->description->hide();
    ui->info->show();
    ui->image->show();
    ui->logo->show();
}

void MainWindow::on_change_color_clicked()
{
    QColorDialog dialog {};
    dialog.setWindowIcon(QIcon(":/imgs/imgs/color_palette.png"));
    dialog.setWindowTitle(QString("Select Background Color"));
    if (dialog.exec() == QColorDialog::Accepted)
        this->setStyleSheet(QString("background-color: ").append(dialog.selectedColor().name() + QString(";")));
    /* Separator */
    if (this->styleSheet() != QString("background-color: lightgreen;")  && this->styleSheet() != QString("background-color: black;")) {
        ui->description->setStyleSheet(QString("color: black;\n font-size: 13px;\n font-weight: bold;"));
        ui->titleLabel->setStyleSheet(QString("font-size: 16px;\n color: black;\n font-weight: bold;"));
    }
}

void MainWindow::keyPressEvent(QKeyEvent *k) {
    switch (k->key()) {
        case Qt::Key_Return:
        on_search_button_clicked();
        break;
        case Qt::Key_Enter:
        on_search_button_clicked();
        break;
    }
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{
    if (arg1.isEmpty())
        ui->text_clear->hide();
    else
        ui->text_clear->show();
}


void MainWindow::on_text_clear_clicked()
{
    ui->lineEdit->clear();
    ui->text_clear->hide();
}
