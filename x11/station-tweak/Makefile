# Created by:	Eric Turgeon ericturgeon@ghostbsd.org
# Date created:	November 11 2013


PORTNAME=	station-tweak
PORTVERSION=	0.3
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	https://github.com/GhostBSD/${PORTNAME}/archive/

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	Mate configuration system.

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	GhostBSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}python-distutils-extra>=2.15:devel/py-python-distutils-extra

RUN_DEPENDS=	wmctrl:x11/wmctrl

USES = python:2.7 gettext-tools
USE_PYTHON=	distutils
USE_GNOME=	pygobject3 intltool

.include <bsd.port.mk>
