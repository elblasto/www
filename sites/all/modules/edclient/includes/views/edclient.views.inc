<?php

function edclient_views_query_alter(&$view, &$query){
    if($view->name == 'clients_')
    {
        //looking to achieve what this line says, but the DatabaseCondition object is protected
             //$query->where[0]['conditions'][0]['field']->condition[0]['field'] = 'field_data_field_phone.field_phone_value';\
               // $query->where[0]['conditions'][0]['value']='47';
        $a = $query->where[0]['conditions'][0]/*['value'];*/['field'];

        $b = new DatabaseCondition();
        // you don't see the contents of the second argument below inside dsm($query)
        $b->condition( 'field_data_field_phone.field_phone_value', $a[0]['value'], 'LIKE');
       // watchdog('edclient',$message=$query->where[0]['conditions'][0]['field'],'WATCHDOG_INFO','','');
        $query->where[0]['conditions'][0]['field'] = $b;

    }

}