# $FreeBSD$

PORTNAME=	kded
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	x11 kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 extensible deamon for providing system level services

USES=		cmake:outsource compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons crash dbusaddons doctools ecm \
		init service
USE_QT=		buildtools_build core dbus gui qmake_build widgets

.include <bsd.port.mk>
