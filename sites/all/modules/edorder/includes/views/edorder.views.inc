<?php
/**
 * Implements hook_views_data_alter().
 * 
 * @param array $data
 */
function edorder_views_data_alter(&$data) {
}

/**
 * Implements hook_views_pre_render(&$view).
 * 
 * @param object $view
 */
function edorder_views_pre_render(&$view) {
  if ($view->name == 'reports') {
    $used_nids = array();
    $new_view_result = array();
    foreach ($view->result as $row) {
      if (!in_array($row->node_field_data_field_product_nid, $used_nids)) {
        $new_view_result[$row->node_field_data_field_product_nid] = $row;
        $used_nids[] = $row->node_field_data_field_product_nid;
      }
      else {
        $current_quantity = $new_view_result[$row->node_field_data_field_product_nid]->field_field_quantity[0]['raw']['value'];
        $out_quantity = $row->field_field_quantity[0]['raw']['value'];
        $new_view_result[$row->node_field_data_field_product_nid]->field_field_quantity[0]['rendered']['#markup'] = $current_quantity + $out_quantity;
      }
    }
    $view->result = $new_view_result;
  }
  
}
