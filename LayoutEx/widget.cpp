#include "widget.h"
#include "ui_widget.h"
#include <QScrollArea>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QListView>
#include <QTreeView>
#include <QTableView>
#include <QListWidget>
#include <QTreeWidget>
#include <QTableWidget>
#include <QColumnView>
#include <QGroupBox>
#include <QToolBox>
#include <QTabWidget>
#include <QStackedWidget>
#include <QDockWidget>
#include <QMainWindow>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    initLayout();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::initLayout()
{
    //15.QDockWidget 悬停窗口 以悬停面板的方式停靠在主窗口的侧边，可以拖拽，合并，浮动，停靠
#ifdef QDockWidgetTest
    //允许Dock窗口间的联动行为
    //这个只能在mianwindow下使用
    QMainWindow *w = new QMainWindow(this);
    w->resize(600, 400);
    w->setDockNestingEnabled(true);

    //添加Dock
    QDockWidget *dock1 = new QDockWidget("D1");
    w->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dock1, Qt::Orientation::Vertical);
    QDockWidget *dock2 = new QDockWidget("D2");
    w->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dock2, Qt::Orientation::Vertical);
    QDockWidget *dock3 = new QDockWidget("D3");
    w->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dock3, Qt::Orientation::Vertical);

    //合并成标签显示
    w->tabifyDockWidget(dock1, dock2);
    w->tabifyDockWidget(dock1, dock3);

    //分开并列显示
//    w->splitDockWidget(dock1, dock2, Qt::Orientation::Horizontal);
//    w->splitDockWidget(dock2, dock3, Qt::Orientation::Horizontal);

    //设置拐角区域属于哪一侧
    w->setCorner(Qt::Corner::BottomLeftCorner, Qt::DockWidgetArea::BottomDockWidgetArea);

    //限制Dock只能显示在固定区域
    dock1->setAllowedAreas(Qt::DockWidgetArea::RightDockWidgetArea);

    //设置Dock不可拖动，不可关闭，不可浮动
    dock1->setFeatures(QDockWidget::NoDockWidgetFeatures);

    //设置Dock可拖动，可关闭，可浮动
//    dock1->setFeatures(
//        QDockWidget::DockWidgetMovable |
//        QDockWidget::DockWidgetClosable |
//        QDockWidget::DockWidgetFloatable);
    w->show();
#endif

    //14.QStackWidget 堆栈窗体 以堆栈形式存储多个界面内容，动态显示其中一个界面 一般配合QComboBox或其它切换控件使用
#ifdef QStackWidgetTest
    //设置每个面板的界面
    QStackedWidget *stackWidget = new QStackedWidget(this);
    stackWidget->insertWidget(stackWidget->count(), new QLabel("Hello-1"));
    stackWidget->insertWidget(stackWidget->count(), new QLabel("Hello-2"));
    stackWidget->insertWidget(stackWidget->count(), new QLabel("Hello-3"));
    stackWidget->insertWidget(stackWidget->count(), new QLabel("Hello-4"));
    stackWidget->insertWidget(stackWidget->count(), new QLabel("Hello-5"));

    //设置显示的界面
    stackWidget->setCurrentIndex(3);
#endif


    //13.QTabWidget 选项卡控件 横向
#ifdef QTabWidgetTest
    QTabWidget *tabWidget = new QTabWidget(this);
    tabWidget->resize(500, 300);
    tabWidget->removeTab(0);
//    tabWidget->removeTab(0);

    //插入标签页
    tabWidget->insertTab(tabWidget->count(), new QLabel("Hello"), "Page-1");
    tabWidget->insertTab(tabWidget->count(), new QLabel("Hello"), "Page-2");
    tabWidget->insertTab(tabWidget->count(), new QLabel("Hello"), "Page-3");
    tabWidget->insertTab(tabWidget->count(), new QLabel("Hello"), "Page-4");
#endif


    //12.QToolBox 竖向选项卡控件 相当于抽屉
#ifdef QToolBoxTest
    //移除QtDesigner默认生成的选项卡
    QToolBox *toolBox = new QToolBox(this);
    toolBox->removeItem(0);

    //添加新的选项卡
    toolBox->addItem(new QLabel("Hello"), "Page-1");
    toolBox->addItem(new QLabel("Hello"), "Page-2");
    toolBox->addItem(new QLabel("Hello"), "Page-3");
    toolBox->addItem(new QLabel("Hello"), "Page-4");
    toolBox->addItem(new QLabel("Hello"), "Page-5");
#endif

    //11.QGroupBox 分组框 带标题的组件
#ifdef QGroupBoxTest
    //设置布局
    QGroupBox *groupBox = new QGroupBox(this);
    groupBox->setTitle("Test");
    QHBoxLayout *layout = new QHBoxLayout();
    groupBox->setLayout(layout);

    //添加控件
    layout->addStretch(1);
    QPushButton *button1 = new QPushButton("Button1");
    layout->addWidget(button1, 2);
    QPushButton *button2 = new QPushButton("Button2");
    layout->addWidget(button2, 2);
#endif



    //10.QColumnView 列视图控件 一列展开后，可以显示子列内容
#ifdef QColumnViewTest
    //绑定数据模型
    QColumnView *columnView = new QColumnView(this);
    columnView->resize(500, 300);
    QStandardItemModel *model = new QStandardItemModel();
    columnView->setModel(model);

    //添加多层列数据
    QStandardItem *item1 = new QStandardItem("record-1");
    QStandardItem *item2 = new QStandardItem("record-2");
    QStandardItem *item3 = new QStandardItem("record-3");
    model->appendRow(item1);
    model->appendRow(item2);
    model->appendRow(item3);
    QStandardItem *item11 = new QStandardItem("record-1-1");
    QStandardItem *item12 = new QStandardItem("record-1-2");
    QStandardItem *item13 = new QStandardItem("record-1-3");
    item1->appendRow(item11);
    item1->appendRow(item12);
    item1->appendRow(item13);
    QStandardItem *item131 = new QStandardItem("record-1-3-1");

#endif


    //9.QTableWidget 表格控件 通过QTableWidgetItem控制
#ifdef QTableWidgetTest
    //设置表格标题
    QTableWidget *tableWidget = new QTableWidget(this);
    tableWidget->resize(500, 300);
    tableWidget->setColumnCount(3);
    tableWidget->setRowCount(10);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "A" << "B" << "C");
    tableWidget->setVerticalHeaderLabels(QStringList() << "R1" << "R2" << "R3");

    //设置表格数据
    tableWidget->setItem(0, 0, new QTableWidgetItem("A1"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("B1"));
    tableWidget->setItem(0, 2, new QTableWidgetItem("C1"));
    tableWidget->setItem(1, 0, new QTableWidgetItem("A2"));
    tableWidget->setItem(1, 1, new QTableWidgetItem("B2"));
#endif



    //8.QTreeWidget 树状控件 通过QTreeWidgetItem直接控制
#ifdef QTreeWidgetTest
    //设置列标题
    QTreeWidget *treeWidget = new QTreeWidget(this);
    treeWidget->resize(500, 300);
    treeWidget->setColumnCount(3);
    treeWidget->setHeaderLabels(QStringList() << "A" << "B" << "C");

    //设置顶层数据
    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList() << "item-1" << "B" << "C");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList() << "item-2" << "B" << "C");
    treeWidget->insertTopLevelItem(0, item1);
    treeWidget->insertTopLevelItem(1, item2);

    //设置下级数据
    item1->addChild(new QTreeWidgetItem(QStringList() << "item-1-1" << "B" << "C"));
    item1->addChild(new QTreeWidgetItem(QStringList() << "item-1-2" << "B" << "C"));
    item1->addChild(new QTreeWidgetItem(QStringList() << "item-1-3" << "B" << "C"));
#endif


    //7.QListWidget 列表控件  直接使用Item设置内容,通过QListWidgetItem
#ifdef QListWidgetTest
    QListWidget *listWidget = new QListWidget(this);

    //直接添加Item
    QListWidgetItem *item1 = new QListWidgetItem("item-1");
    QListWidgetItem *item2 = new QListWidgetItem("item-2");
    QListWidgetItem *item3 = new QListWidgetItem("item-3");
    listWidget->addItem(item1);
    listWidget->addItem(item2);
    listWidget->addItem(item3);
#endif


    //6.QTableView 表格控件 通过model来刷新数据
#ifdef QTableViewTest
    //获取QTableView
    QTableView *tableView = new QTableView(this);
    tableView->resize(500, 300);

    //设置是否可编辑
    tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    //设置整行选中
    tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置只能选中单条记录
    tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //显示表头
//    tableView->horizontalHeader()->setVisible(true);
//    tableView->verticalHeader()->setVisible(true);
    //显示网格线
    tableView->setShowGrid(true);
    //设置网格线风格
    tableView->setGridStyle(Qt::DotLine);

    //绑定数据模型
    QStandardItemModel *model = new QStandardItemModel();
    QStringList horizontalHeaderList = QStringList() << "A" << "B" << "C";
    QStringList verticalHeaderList = QStringList() << "1" << "2" << "3";
    model->setHorizontalHeaderLabels(horizontalHeaderList);
    model->setVerticalHeaderLabels(verticalHeaderList);
    tableView->setModel(model);

    //添加数据
    model->setItem(0, 0, new QStandardItem("A1"));
    model->setItem(0, 1, new QStandardItem("A2"));
    model->setItem(0, 2, new QStandardItem("A3"));
    model->setItem(1, 0, new QStandardItem("B1"));
    model->setItem(1, 1, new QStandardItem("B2"));
    model->setItem(1, 2, new QStandardItem("B3"));

    //设置表格样式
    tableView->setStyleSheet(
        "QTableView {"
        "	color: rgba(0,0,0,0.8);"
        "	selection-background-color: deepskyblue;"
        "}"
    );
#endif


    //5.QTreeView 树状控件 通过model控制
#ifdef QTreeViewTest
    //为QTreeView绑定数据模型
    QTreeView *treeView = new QTreeView(this);
    treeView->resize(500, 300);
    QStandardItemModel *model = new QStandardItemModel();
    treeView->setModel(model);

    //设置横向标题
    QStringList hHeaderList = QStringList() << "A" << "B" << "C" << "D";
    model->setHorizontalHeaderLabels(hHeaderList);

    //设置三级树结构数据
    QStandardItem *item1 = new QStandardItem("Item 1");
    model->appendRow(item1);
    QStandardItem *item11 = new QStandardItem("Item 1-1");
    item1->appendRow(item11);
    item1->appendRow(new QStandardItem("Item 1-2"));
    item1->appendRow(new QStandardItem("Item 1-3"));
    item1->appendRow(new QStandardItem("Item 1-4"));
    item11->appendRow(new QStandardItem("Item 1-1-1"));
    item11->appendRow(new QStandardItem("Item 1-1-2"));
    item11->appendRow(new QStandardItem("Item 1-1-3"));

    //设置其它列数据
    model->setItem(0, 1, new QStandardItem("Hello"));
    model->setItem(0, 2, new QStandardItem("Hello"));
    model->setItem(0, 3, new QStandardItem("Hello"));
    model->setItem(0, 4, new QStandardItem("Hello"));
#endif


    //4.QListView 列表控件
#ifdef QListViewTest
    // 创建数据模型
    // QStandardItem可以直接用string作为数据，也可以通过setData设置复杂数据
    QStandardItemModel  *model  =  new  QStandardItemModel();
    model->appendRow(new  QStandardItem("item1"));
    model->appendRow(new  QStandardItem("item2"));
    model->appendRow(new  QStandardItem("item3"));
    model->appendRow(new  QStandardItem("item4"));
    model->appendRow(new  QStandardItem("item5"));

    // 绑定数据模型
    QListView  *listView  =  new QListView(this);
    listView->setModel(model);

    // 绑定ItemDelegate
    // ItemDelegate可以决定如何绘制一个复杂的Item，可用于显示复杂的Model数据
//    listView->setItemDelegate(nullptr);
#endif


    //3.QGridLayout 网格布局 按照行列将布局划分为若干份
#ifdef QGridLayoutTest
    QGridLayout *gridLayout = new QGridLayout(this);

    //设置布局参数，这里以一个4*4等宽等高的网格为例
    //四行按1:1:1:1的比例关系占据布局空间
    gridLayout->setRowStretch(0, 1);
    gridLayout->setRowStretch(1, 1);
    gridLayout->setRowStretch(2, 1);
    gridLayout->setRowStretch(3, 1);
    //四列按1:1:1:1的比例关系占据布局空间
    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 1);
    gridLayout->setColumnStretch(2, 1);
    gridLayout->setColumnStretch(3, 1);
    //设置水平竖直间距
    gridLayout->setHorizontalSpacing(5);
    gridLayout->setVerticalSpacing(5);

    //创建若干按钮
    QPushButton *button1 = new QPushButton("1");
    QPushButton *button2 = new QPushButton("2");
    QPushButton *button3 = new QPushButton("3");
    QPushButton *button4 = new QPushButton("4");

    //从第一行第一列开始添加按钮，占据一行一列的空间
    gridLayout->addWidget(button1, 0, 0, 1, 1);
    //从第一行第二列开始添加按钮，占据一行三列的空间
    gridLayout->addWidget(button2, 0, 1, 1, 3);
    //从第二行第三列添加按钮，默认占据一行一列的空间
    gridLayout->addWidget(button3, 1, 2);
    //从尾行的末列之后，或新行的首列开始添加按钮
//    gridLayout->addWidget(button4);
    //按钮垂直策略更改就能占用两行
    QSizePolicy policy = button4->sizePolicy();
    policy.setVerticalPolicy(QSizePolicy::Expanding);
    button4->setSizePolicy(policy);
    gridLayout->addWidget(button4, 2, 1, 2, 1);
#endif

    //2.QHBoxLayout 水平布局 所有子控件横向排列
#ifdef QHBoxLayoutTest
    //创建一个按钮
   QPushButton *button = new QPushButton(this);
   button->setGeometry(0, 0, 200, 50);
   button->setText("TEST");

   //设置水平布局
   QHBoxLayout *hLayout = new QHBoxLayout(this);

   //按钮居中，左右的弹性区域按照1:2的比例分配剩余空间
   hLayout->addStretch(1);
   hLayout->addWidget(button);
   hLayout->addStretch(2);
#endif

    //1.QScrollArea 滚动面板 如果子控件超出控件范围则有滚动条
#ifdef QScrollAreaTest
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->resize(500, 500);
    QWidget *contentWidget = new QWidget();
    scrollArea->setWidget(contentWidget);
    QVBoxLayout *layout = new QVBoxLayout();
    contentWidget->setLayout(layout);

    // 调整内容面板大小
    // 如果resizable=false，内容面板会和ScrollArea一样大小
    // 对于QVBoxLayout来说，这也做的结果就是，没有滚动条，100个item平分ScrollArea的高度
    scrollArea->setWidgetResizable(true);
    for (int i = 0; i < 100; i++)
        layout->addWidget(new QLabel("Hello"));
#endif
}

