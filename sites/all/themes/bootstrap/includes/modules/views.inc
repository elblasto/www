<?php

/**
 * @file
 * Provides views theme override functions for Bootstrap themes.
 */

/**
 * Display a view as a table style.
 */
function bootstrap_preprocess_views_view_table(&$vars) {
  $vars['classes_array'][] = 'table table-striped table-hover';
}

function bootstrap_preprocess_views_view_grid(&$vars) {
  $vars['class'] .= ' table table-striped table-hover';
}
