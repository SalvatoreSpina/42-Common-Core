#!/bin/sh

# Set the Database Credentials
sed -i 's|DOMAIN_NAME|'${DOMAIN_NAME}'|g' /wordpress/wp-config.php
sed -i 's|DATABASE_HOST|'${DATABASE_HOST}'|g' /wordpress/wp-config.php
sed -i 's|DATABASE_NAME|'${DATABASE_NAME}'|g' /wordpress/wp-config.php
sed -i 's|DATABASE_USER|'${DATABASE_USER}'|g' /wordpress/wp-config.php
sed -i 's|DATABASE_PASS|'${DATABASE_PASS}'|g' /wordpress/wp-config.php

wp core install --url="sspina.42.fr" --title="Sasso Stark" --admin_user="sasso" --admin_password="pizza" --admin_email="no@thanks.com" --skip-email
wp plugin install hello-dolly --activate
wp theme install twentytwenty --activate
wp plugin update --all
wp user create sspina sspina@42.com --role=author --user_pass=sspina
wp post create --post_title="Pizza" --post_content="Only if it's Italian" --post_status=publish --post_author="sasso"

# Copy Folder of redis-cache to mounted volume
cp -r redis-cache/ /wordpress/wp-content/plugins/
# Copy Folder of WordPress to mounted volume
cp -r /wordpress/* /var/www/html/wordpress/

# This is a variant of PHP that will run in the background as a daemon, listening for CGI requests.
php-fpm7 -FR
