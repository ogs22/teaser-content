<?php
/**
 * @file
 * teaser_content.features.inc
 */

/**
 * Implements hook_node_info().
 */
function teaser_content_node_info() {
  $items = array(
    'teaser_page' => array(
      'name' => t('Teaser page'),
      'base' => 'node_content',
      'description' => t('http://maths.org/~ogs22/Project-Light/components/inpage-components/teasers.html'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}


/**
 * Implements hook_theme_registry_alter().
 */
function teaser_content_theme_registry_alter(&$theme_registry) {
  $extension   = '.tpl.php';
  $module_path = drupal_get_path('module', 'teaser_content');
  $files       = file_scan_directory($module_path . '/templates', '/' . preg_quote($extension) . '$/');
  foreach ($files as $file) {
	$template = drupal_basename($file->filename, $extension);
	$theme    = str_replace('-', '_', $template);
	list($base_theme, $specific) = explode('__', $theme, 2);


	// Don't override base theme.
	if (!empty($specific) && isset($theme_registry[$base_theme])) {
	  $theme_info = array(
		'template'   => $template,
		'path'       => drupal_dirname($file->uri),
		'variables'  => $theme_registry[$base_theme]['variables'],
		'base hook'  => $base_theme,
		// Other available value: theme_engine.
		'type'       => 'module',
		'theme path' => $module_path,
	  );


	  $theme_registry[$theme] = $theme_info;
	}
  }
}