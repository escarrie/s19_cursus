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

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'password' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8mb4' );

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
define( 'AUTH_KEY',         '@`S_:nuQ.1,sLR)37S!0|XH%~quXbH`3M-5te._|vf!LE,,V<98JAI+8:{tXw16`' );
define( 'SECURE_AUTH_KEY',  '[[d)QK.htY@y-J#tQOG1*M!WD#7;^nC,nB7S<vJ>c`KB){{PiDYW6qs7BQCi./Jw' );
define( 'LOGGED_IN_KEY',    'cal!Mj).EP}. V|H(>hn:ki}JqroXxf_=YciM[DZ^C@euaSrk`yz_2T[o7LXk%iv' );
define( 'NONCE_KEY',        'qVXuU>cxkg5>WjvH{GPTLQkD=-2sM>?=.B5j#{v/s>6kFy-x67r}>j{Wvb!jyl,c' );
define( 'AUTH_SALT',        'yeVc<h)M5*(%m{DtQM`ankF_#WwH,zNubf72ir},Nx/rbAx0XXk2NpJ(9%<jeVOW' );
define( 'SECURE_AUTH_SALT', 'H77Ab+*~x2LZCVyJCw#P I@I%1+wDD:$3sH&c|?F^7V<pC0|m9Yij{V%eJ0Qx6{T' );
define( 'LOGGED_IN_SALT',   'ah{bC(<ZZ`o}.<cmyI`W4Vx.$5-Fv9[2{eG<{C8i3F.`Wg*`vugkm#Cf$GA.)tV/' );
define( 'NONCE_SALT',       'hDnjF;zi+Jm>bx~(UqUf&?Qo_=~`!eYLH@q7H%}BgkA8Vr#`uol_?rVfom|!> *Q' );

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
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
