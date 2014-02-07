<?php

/**
 * List all example predicates.
 */
function client_list() {
// Call your hook_entity_info implementation, 'cause it includes all your bundles.
  $client = edclient_entity_info();
  $headers = array(t('Name')); // Table Headers
  $rows = array();
  foreach ($client['client']['bundles'] as $name => $bundle) {
    $rows[] = array($bundle['label']);
  }
  // Format the table array. This is a pretty simple table, you could include
  // links to the field management pages for each bundle too.
  $output = array(
    '#theme' => 'table',
    '#header' => $headers,
    '#rows' => $rows,
  );
  return $output;
}

/**
 * Create form array.
 */
function client_add($form, &$form_state) {
  $client = new stdClass();
  $client->type = 'client';
  // Create the temporary form/state by reference
  field_attach_form('client', $client, $form, $form_state);
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Сохранить'),
    '#weight' => 50,
    '#prefix' => '<div class="form-actions form-wrapper">',
    '#suffix' => '</div>',
  );
  return $form;
}

/**
 * Form submit for add client.
 */
function client_add_submit($form, &$form_state) {
  global $user; 
  $entity = entity_create('client', array('type' =>'client'));
  $entity->uid = $user->uid;
  $entity->created = time();
  field_attach_submit('client', $entity, $form, $form_state);
  $entity->save();
  drupal_goto('clients');
}


/**
 * Delete a client
 */
function _client_delete($form, &$form_state, $cid) { 
  $form['cid'] = array(
    '#type' => 'value',
    '#value' => $cid,
  );
  return confirm_form($form, t('Вы уверены, что хотите удалить клиента?'), 'clients', t('Удалив клиента, также будут удалены все записи связанные с ним (заказы, бонусы, карты). Это действие нельзя будет отменить.'), t('Delete'), t('Cancel'));
}

/**
 * Delete a client
 */
function _client_delete_submit($form, &$form_state) { 
  entity_delete('client', $form_state['values']['cid']);
  drupal_goto('clients');
  drupal_set_message(t('Клиент удален.'));
}

