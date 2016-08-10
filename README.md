# drush-utils

## Installation:

Just put the sqlsync_registry.drush.inc and sqlsync_run.drush.inc  file in your ~/.drush directory.

## Usage

To use those features, copy the 'target-command-specific' item from the example aliases above, place it in your development site aliases, and customize the development module list to suit.

### Registry Rebuild

*Note: You need to have the drush `registry-rebuild` module installed to use that command*

```
$aliases['dev'] = array (
 'root' => '/srv/www/drupal',
 'uri' => 'site.com',
 'target-command-specific' => array(
   'sql-sync'  => array(
     'registry-rebuild'  => TRUE,
   ),
 ),
);
```
### Run

```
$aliases['dev'] = array (
 'root' => '/srv/www/drupal',
 'uri' => 'site.com',
 'target-command-specific' => array(
   'sql-sync'  => array(
     'run'  => array('/path/to/script1', '/path/to/script2'),
   ),
 ),
);
```
