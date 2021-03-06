--- Telegram/SourceFiles/logs.cpp.orig	2018-09-28 13:08:38 UTC
+++ Telegram/SourceFiles/logs.cpp
@@ -332,7 +332,7 @@ void start(not_null<Core::Launcher*> lau
 
 	if (cAlphaVersion()) {
 		workingDirChosen = true;
-#if defined Q_OS_MAC || defined Q_OS_LINUX
+#if defined Q_OS_MAC || defined Q_OS_LINUX || defined Q_OS_FREEBSD
 	} else {
 #ifdef _DEBUG
 		cForceWorkingDir(cExeDir());
@@ -346,15 +346,15 @@ void start(not_null<Core::Launcher*> lau
 #endif // !_DEBUG
 		workingDirChosen = true;
 
-#if defined Q_OS_LINUX && !defined _DEBUG // fix first version
+#if (defined Q_OS_LINUX || defined Q_OS_FREEBSD) && !defined _DEBUG // fix first version
 		moveOldDataFrom = initialWorkingDir;
-#endif // Q_OS_LINUX && !_DEBUG
+#endif // (Q_OS_LINUX || Q_OS_FREEBSD) && !_DEBUG
 
-#elif defined Q_OS_WINRT // Q_OS_MAC || Q_OS_LINUX
+#elif defined Q_OS_WINRT // Q_OS_MAC || Q_OS_LINUX || Q_OS_FREEBSD
 	} else {
 		cForceWorkingDir(psAppDataPath());
 		workingDirChosen = true;
-#elif defined OS_WIN_STORE // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT
+#elif defined OS_WIN_STORE // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || Q_OS_FREEBSD
 #ifdef _DEBUG
 		cForceWorkingDir(cExeDir());
 #else // _DEBUG
@@ -368,7 +368,7 @@ void start(not_null<Core::Launcher*> lau
 			cForceWorkingDir(cWorkingDir());
 			workingDirChosen = true;
 		}
-#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE
+#endif // Q_OS_MAC || Q_OS_LINUX || Q_OS_WINRT || OS_WIN_STORE || Q_OS_FREEBSD
 	}
 
 	LogsData = new LogsDataFields();
