#include "image_provider.h"
#include "src/common.h"

ImageProvider::ImageProvider()
	: QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

QPixmap ImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestSize)
{
	Q_UNUSED(size);
	Q_UNUSED(requestSize);
	// LOG << id;

	QPixmap res = objMap[id];
	// LOG << res;

	return res;
}

QString ImageProvider::addImage(QString id, QImage &img)
{

	QPixmap pixmap = QPixmap::fromImage(img);
	// LOG << img;
	
	objMap.insert(id, pixmap);
	return id;
}
