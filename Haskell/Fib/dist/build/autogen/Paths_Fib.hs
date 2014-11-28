module Paths_Fib (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch


version :: Version
version = Version {versionBranch = [0,1,0,0], versionTags = []}
bindir, libdir, datadir, libexecdir :: FilePath

bindir     = "/home/parham/.cabal/bin"
libdir     = "/home/parham/.cabal/lib/Fib-0.1.0.0/ghc-7.6.3"
datadir    = "/home/parham/.cabal/share/Fib-0.1.0.0"
libexecdir = "/home/parham/.cabal/libexec"

getBinDir, getLibDir, getDataDir, getLibexecDir :: IO FilePath
getBinDir = catchIO (getEnv "Fib_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "Fib_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "Fib_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "Fib_libexecdir") (\_ -> return libexecdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
