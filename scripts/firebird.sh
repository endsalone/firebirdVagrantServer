#!/usr/bin/env bash

echo ">>> Installing Firebird"

[[ -z $1 ]] && { echo "!!! Firebird root password not set. Check the Vagrant file."; exit 1; }

sudo add-apt-repository -y ppa:mapopa

sudo apt-get update

sudo debconf-set-selections <<< "firebird2.5-super shared/firebird/enabled boolean true"
sudo debconf-set-selections <<< "firebird2.5-super shared/firebird/sysdba_password/first_install password $1"

sudo apt-get install -y firebird2.5-super

sudo service firebird2.5-super start

sudo apt-get install -y firebird2.5-examples firebird2.5-dev

cd /usr/share/doc/firebird2.5-examples/examples/empbuild/
sudo gunzip employee.fdb.gz
sudo chown firebird.firebird employee.fdb
sudo mv employee.fdb /var/lib/firebird/2.5/data/
