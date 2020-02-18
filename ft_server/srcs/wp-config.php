<?php
define('DB_NAME', 'wordpress');
define('DB_USER', 'user');
define('DB_PASSWORD', 'password');
define('DB_HOST', 'localhost');
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');
define('AUTH_KEY',         '+*:LCZpdyKYS.pg-?HL9;-4D=gs!G!Uqbs/{*Mj!OSAppe-V!~7%U3jB^k%+M:$-');
define('SECURE_AUTH_KEY',  'IcHLgv.}VrQj<i2jji-wiE^UwJ *@2+]H|_yUz}:6s=|Kkh4Av73|neOt<?|JBS{');
define('LOGGED_IN_KEY',    '-~,1TU17=;:prQ.)7Bb~#aj1Bj^M{}p=fhWi@s,obR~IX?<#i%v)^B7(8xOX&8^G');
define('NONCE_KEY',        '%`{jSg71Q<|Cc`bqU<+43~[SyL)~Wfbs@,FHBpZA>d4rM,)4|Xd67omQmGUuHd[p');
define('AUTH_SALT',        'uV:v4ZNB!$-yK;dmW^2Nkr41x9o2I7OfT:gt;o7zJ[}Lo:*m@9=-l!3?Z9pI{ZU#');
define('SECURE_AUTH_SALT', 'gE48G*0PXo#+Icg@6z<1?/%Bg)8?)PjlId2G/rQWa>L$H -9;0fcw/2pi9A#}Moe');
define('LOGGED_IN_SALT',   '#`f4/{V.Zz-+;08m,uU^~9yGc1{?jaD#a+3>K%- LDX7!7F6.T&mnesGI0qs*TR8');
define('NONCE_SALT',       'ZxA]T(0 !ckE+vH( 9-I -o|K|(.>;zqm1+KOgu1nowYXyDk;6RW-`9PF9|z+r(_');
$table_prefix = 'wp_';
define('WP_DEBUG', false);
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');
require_once(ABSPATH . 'wp-settings.php'); 
?>