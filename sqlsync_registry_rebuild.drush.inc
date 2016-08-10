<?php

/**
 * @file
 * Example "Sync registry-rebuild" sql-sync command alter.
 *
 * Sync_registry_rebuild adds option to sql-sync to run registry-rebuild.
 *
 * For example:
 *
 * @code
 * $aliases['dev'] = array (
 *   'root' => '/srv/www/drupal',
 *   'uri' => 'site.com',
 *   'target-command-specific' => array(
 *     'sql-sync'  => array(
 *       'registry-rebuild'  => TRUE,
 *     ),
 *   ),
 * );
 * @endcode
 *
 * To use this feature, copy the 'target-command-specific'
 * item from the example alias above, place it in your development
 * site aliases, and customize the development module list
 * to suit.  You must also copy the sync_run.drush.inc
 * file to a location where Drush will find it, such as
 * $HOME/.drush.  See `drush topic docs-commands` for more
 * information.
 *
 */

/**
 * Implements hook_drush_help_alter().
 *
 * When a hook extends a command with additional options, it must
 * implement help alter and declare the option(s).  Doing so will add
 * the option to the help text for the modified command, and will also
 * allow the new option to be specified on the command line.  Without
 * this, Drush will fail with an error when a user attempts to use
 * the option.
 */
function sqlsync_registry_rebuild_drush_help_alter(&$command) {
  if ($command['command'] == 'sql-sync') {
    $command['options']['registry-rebuild']  = "Run registry-rebuild after the sync operation has completed.";
  }
}

/**
 * Implements drush_hook_post_COMMAND().
 *
 * The post hook is only called if the sql-sync operation completes
 * without an error.  When called, we check to see if the user specified
 * any modules to enable/disable.  If so, we will call run for
 * each script.
 */
function drush_sqlsync_registry_rebuild_post_sql_sync($source = NULL, $destination = NULL) {
  $script = drush_get_option_list('registry-rebuild');
  if (!empty($script)) {
    drush_log(dt("Run registry_rebuild post-sql-sync"));
    drush_invoke_process($destination, 'registry-rebuild', array());
  }
}
