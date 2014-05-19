[![Build Status](https://travis-ci.org/Qucs/qucs.svg?branch=master)](https://travis-ci.org/Qucs/qucs)

## QUCS - Quite Universal Circuit Simulator

<http://sourceforge.net/projects/qucs>


### Download the source

Repositories (official and mirror):

    git clone git://git.code.sf.net/p/qucs/git
    git clone git://github.com/Qucs/qucs.git

For development conveninence ADMS is provided as a Git submodule.
To download the ADMS submodule either:

   * clone submodules recursively:
     * `git clone --recursive [repository]`
   * or after cloning, do:
     * `git submodule init`
     * `git submodule update`

### Compile instructions Linux (Debian/Ubuntu)

First make sure you have all dependencies installed:

    sudo apt-get install build-essential
    sudo apt-get install libqt4-dev libqt4-qt3support
    sudo apt-get install automake libtool gperf flex bison

For ADMS

    sudo apt-get install libxml2 libxml2-dev
    sudo apt-get install zlib1g zlib1g-dev
    sudo apt-get install libgd2-xpm-dev

Install Perl modules for ADMS. Configure cpan, no waiting for user input.

    (echo y;echo o conf prerequisites_policy follow;echo o conf commit)| sudo cpan
    sudo cpan -i XML::LibXML
    sudo cpan -f GD

Compile qucs:

    cd qucs
    ./autogen.sh
    ./configure --enable-maintainer-mode
    make
    sudo make install

Compile qucs-core:

    cd qucs-core
    ./bootstrap.sh
    ./configure --enable-maintainer-mode
    make
    sudo make install

Note:

 * Qucs it will be installed by default to `/usr/local/`. This can be modified by passing `--prefix=[some location]` to the `./configure` script.

 * ADMS can be installed from a released tarball (>= 2.3.0). To use an already available `admsXml` pass the option `--with-mkadms=[path/to/admsXml]` to the `./configure` script


