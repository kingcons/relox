class TmattioRelox < Formula
  VERSION = '0.1.0'
  desc 'A lox interpreter in ReasonML'
  homepage 'https://github.com/kingcons/relox'
  url "https://github.com/kingcons/relox/releases/download/v#{VERSION}/relox-darwin-x64.zip"
  version VERSION

  bottle :unneeded

  test do
  end

  def install
    mv "relox.exe", "relox"
    bin.install 'relox'
  end
end
