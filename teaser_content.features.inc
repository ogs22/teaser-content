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
      'description' => t('Use this page if you need a portal type page linking to many other pages
Requires at least 4 pieces of content to work properly max 6
Images need to be 316px * 316px and will scale with the page.

http://maths.org/~ogs22/Project-Light/components/inpage-components/teasers.html'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
