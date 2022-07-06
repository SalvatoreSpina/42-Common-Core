<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

define('NONCE_SALT', 'Pizza');

define('WP_CACHE', true);

define('WP_REDIS_HOST', 'redis');
define('WP_CACHE_KEY_SALT', 'DOMAIN_NAME');

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'DATABASE_NAME' );

/** MySQL database username */
define( 'DB_USER', 'DATABASE_USER' );

/** MySQL database password */
define( 'DB_PASSWORD', 'DATABASE_PASS' );

/** MySQL hostname */
define( 'DB_HOST', 'DATABASE_HOST' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         'j#)L!cz[[hMQG~5Oq6q*J|sH$svu#<CA7Ztf`|R-+T(L7rkO0:4Dq` |I Lg[6[N');
define('SECURE_AUTH_KEY',  'hK,(uk%OW7thysw+QGVlH)*WC*=W5)^/jd@&hexH!Ii~2q^GZ3JQ+cyJoz=V#gKd');
define('LOGGED_IN_KEY',    '`y?h~(OA?beyGg~8D}pC?eC&8.#.6{iZ|m>Zir3d}S?ejz}]P{Md *^+EDi|S29Q');
define('NONCE_KEY',        'H:qw?KT-Y:D8FqYpOfJ4FE+L90qm2ZjL:JTyI&PZ -`heH<Vs){cUr`<daUcE?`N');
define('AUTH_SALT',        'ul=-#WP1C9s,IK;|R,)vcb VKPqBR[nYortmGY^p7<p:E=h}uVAm6j>BBpr.mTA%');
define('SECURE_AUTH_SALT', 'bu,h&0&@l)PhQ+?_?6B-<7@bGb-i;wCE=1,|2vQ6#@44t0G0|wI{$hp`|$L3e@MZ');
define('LOGGED_IN_SALT',   '18IW:GtSjvQh[w3Aauaq1$*eUO?nlP-bVDvPwrMORg.1[A3x~/97e5OV_S9+9yds');
define('NONCE_SALT',       'Tji0eiy;|.7uHmWn0_7g^W`LLgi=WU%j(D5*U (%e4(ehcur>GvYnPE-TmGtulHe');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', dirname( __FILE__ ) . '/' );
}

/** Sets up WordPress vars and included files. */
require_once( ABSPATH . 'wp-settings.php' );
