# $FreeBSD$

PORTNAME=	Term-Clui
PORTVERSION=	1.70
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tj@FreeBSD.org
COMMENT=	Perl module offering a Command-Line User Interface

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Term-Size>=0:devel/p5-Term-Size \
		p5-Term-ReadKey>=2.14:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
