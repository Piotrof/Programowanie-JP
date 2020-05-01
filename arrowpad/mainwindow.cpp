
#include <QtWidgets>

#include "arrowpad.h"
#include "mainwindow.h"

MainWindow::MainWindow()
{
//! [0]
    arrowPad = new ArrowPad;
//! [0]
    setCentralWidget(arrowPad);

//! [1]
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
//! [1]

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);
}
