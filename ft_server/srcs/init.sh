#To install new packages
apt-get update && apt-get install -y
#To download files from web
apt-get install -y wget
#Install nginx for the webserver
apt-get install -y nginx
#php-fpm = communication between php and webserver
#php-mysql = module mysql for php and install php 
apt-get install -y php-fpm php-mysql
#mariadb = mysql for debian 10
apt-get install -y mariadb-server
#php modules maybe used by wordpress
apt-get install -y php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
service nginx start
mv nginx.conf /etc/nginx/sites-available/nginx.conf
#symlink to enable our nginx.conf
ln -s /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/
unlink /etc/nginx/sites-enabled/default
mkdir var/www/mysite
wget -c https://wordpress.org/latest.tar.gz
tar -xvzf latest.tar.gz
mv wordpress/* var/www/mysite
mv wp-config.php var/www/mysite
wget https://files.phpmyadmin.net/phpMyAdmin/4.9.0.1/phpMyAdmin-4.9.0.1-english.tar.gz
tar xvf phpMyAdmin-4.9.0.1-english.tar.gz
mkdir /var/www/mysite/phpmyadmin
mv phpMyAdmin-4.9.0.1-english/* /var/www/mysite/phpmyadmin/
mv start.sql /var/www/
service mysql start
mysql < /var/www/start.sql
#create the self-signed certificate
openssl req -x509 -out localhost.crt -keyout localhost.key \
  -newkey rsa:2048 -nodes -sha256 \
  -subj '/CN=localhost' -extensions EXT -config <( \
   printf "[dn]\nCN=localhost\n[req]\ndistinguished_name = dn\n[EXT]\nsubjectAltName=DNS:localhost\nkeyUsage=digitalSignature\nextendedKeyUsage=serverAuth")
mv localhost.crt /etc/ssl/certs/
mv localhost.key /etc/ssl/certs/
service nginx restart
service php7.3-fpm start
service mysql restart
