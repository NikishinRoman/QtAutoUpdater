#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QApplication::setWindowIcon(QIcon(QStringLiteral(":/icons/main.ico")));
	QApplication::setApplicationDisplayName(QStringLiteral("Widgets-Test"));

	qputenv("PLUGIN_UPDATERS_PATH", DBG_PLUGIN_DIR);

	QTranslator tr;
	tr.load(QLocale(),
			QStringLiteral("qtautoupdatergui"),
			QStringLiteral("_"),
			QApplication::applicationDirPath());
	QApplication::installTranslator(&tr);
	
	MainWindow w;
	w.show();
	
	return a.exec();
}
