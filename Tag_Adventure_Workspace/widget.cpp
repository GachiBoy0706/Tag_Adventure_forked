#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QPalette pall;
    ui->setupUi(this);
    this->setWindowTitle("Tag_Adventure_Platy");
    pall.setBrush(this->backgroundRole(), Qt::lightGray);
    this->setPalette(pall);
    this->setAutoFillBackground(true);

    QLabel* lb1 = new QLabel(this);
    QLabel* lb2 = new QLabel(this);
    QLabel* lb3 = new QLabel(this);
    QLabel* lb4 = new QLabel(this);
    QLabel* lb5 = new QLabel(this);
    QLabel* lb6 = new QLabel(this);
    QLabel* lb7 = new QLabel(this);
    QLabel* lb8 = new QLabel(this);
    QLabel* lb9 = new QLabel(this);
    QLabel* lb10 = new QLabel(this);
    QLabel* lb11 = new QLabel(this);
    QLabel* lb12 = new QLabel(this);
    QLabel* lb13 = new QLabel(this);
    QLabel* lb14 = new QLabel(this);
    QLabel* lb15 = new QLabel(this);
    QLabel* lb16 = new QLabel(this);

    QPixmap pix;
    pix.load(":resourses/images/1.jpg");
    lb1->resize(pix.size());
    lb1->setPixmap(pix);
    pix.load(":resourses/images/2.jpg");
    lb2->resize(pix.size());
    lb2->setPixmap(pix);
    pix.load(":resourses/images/3.jpg");
    lb3->resize(pix.size());
    lb3->setPixmap(pix);
    pix.load(":resourses/images/4.jpg");
    lb4->resize(pix.size());
    lb4->setPixmap(pix);
    pix.load(":resourses/images/5.jpg");
    lb5->resize(pix.size());
    lb5->setPixmap(pix);
    pix.load(":resourses/images/6.jpg");
    lb6->resize(pix.size());
    lb6->setPixmap(pix);
    pix.load(":resourses/images/7.jpg");
    lb7->resize(pix.size());
    lb7->setPixmap(pix);
    pix.load(":resourses/images/8.jpg");
    lb8->resize(pix.size());
    lb8->setPixmap(pix);
    pix.load(":resourses/images/9.jpg");
    lb9->resize(pix.size());
    lb9->setPixmap(pix);
    pix.load(":resourses/images/10.jpg");
    lb10->resize(pix.size());
    lb10->setPixmap(pix);
    pix.load(":resourses/images/11.jpg");
    lb11->resize(pix.size());
    lb11->setPixmap(pix);
    pix.load(":resourses/images/12.jpg");
    lb12->resize(pix.size());
    lb12->setPixmap(pix);
    pix.load(":resourses/images/13.jpg");
    lb13->resize(pix.size());
    lb13->setPixmap(pix);
    pix.load(":resourses/images/14.jpg");
    lb14->resize(pix.size());
    lb14->setPixmap(pix);
    pix.load(":resourses/images/15.jpg");
    lb15->resize(pix.size());
    lb15->setPixmap(pix);
    pix.load(":resourses/images/16.jpg");
    lb16->resize(pix.size());
    lb16->setPixmap(pix);


    QGridLayout* pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(1, 1, 1, 1);
    pgrdLayout->setSpacing(4);
    pgrdLayout->addWidget(lb1, 0, 0);
    pgrdLayout->addWidget(lb2, 0, 1);
    pgrdLayout->addWidget(lb3, 0, 2);
    pgrdLayout->addWidget(lb4, 0, 3);
    pgrdLayout->addWidget(lb5, 1, 0);
    pgrdLayout->addWidget(lb6, 1, 1);
    pgrdLayout->addWidget(lb7, 1, 2);
    pgrdLayout->addWidget(lb8, 1, 3);
    pgrdLayout->addWidget(lb9, 2, 0);
    pgrdLayout->addWidget(lb10, 2, 1);
    pgrdLayout->addWidget(lb11, 2, 2);
    pgrdLayout->addWidget(lb12, 2, 3);
    pgrdLayout->addWidget(lb13, 3, 0);
    pgrdLayout->addWidget(lb14, 3, 1);
    pgrdLayout->addWidget(lb15, 3, 2);
    pgrdLayout->addWidget(lb16, 3, 3);


    QHBoxLayout* qhbxLayout1 = new QHBoxLayout;
    QPushButton* button1 = new QPushButton();
    QPushButton* button2 = new QPushButton();
    pix.load(":resourses/images/17.png");
    button1->setIcon(pix);
    button1->setIconSize(QSize(70, 70));
    pix.load(":resourses/images/18.png");
    button2->setIcon(pix);
    button2->setIconSize(QSize(70, 70));
    qhbxLayout1->addWidget(button1);
    qhbxLayout1->addWidget(button2);

    QLabel* label1 = new QLabel("<h1><CENTER><font size=20 color = #FFFF00><B>TIME: 10.34</B></CENTER></h1>"
                               "<h1><CENTER><font size=20 color = #FFFF00><B>STEPS: 5</B></CENTER></h1>");
    QLabel* label2 = new QLabel("<h1><CENTER><font size=20 color = #FFFF00><B>SCORE: 12</B></CENTER></h1>");

    QHBoxLayout* qhbxLayout3 = new QHBoxLayout();
    QPushButton* button3 = new QPushButton();
    QPushButton* button4 = new QPushButton();
    pix.load(":resourses/images/19.png");
    button3->setIcon(pix);
    button3->setIconSize(QSize(70, 70));
    pix.load(":resourses/images/20.png");
    button4->setIcon(pix);
    button4->setIconSize(QSize(70, 70));
    qhbxLayout3->addWidget(button3);
    qhbxLayout3->addWidget(button4);

    QVBoxLayout* qvbxLayout = new QVBoxLayout;
    qvbxLayout->addLayout(qhbxLayout1);
    qvbxLayout->addWidget(label1);
    qvbxLayout->addWidget(label2);
    qvbxLayout->addLayout(qhbxLayout3);

    QHBoxLayout* qhbxLayout2 = new QHBoxLayout;
    qhbxLayout2->addLayout(pgrdLayout);
    qhbxLayout2->addLayout(qvbxLayout);
    this->setLayout(qhbxLayout2);
}

Widget::~Widget()
{
    delete ui;
}

