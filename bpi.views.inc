<?php
/**
 * @file
 *  Views definition for my bpi.
 */

/**
 * Implements hook_views_data().
 */
function bpi_views_data() {
  $data = array();
  $data['bpi_syndicated']['table']['group'] = t('BPI');
  $data['bpi_syndicated']['table']['base'] = array(
    'field' => 'id',
    'title' => t('BPI table'),
    'help' => t('BPI table'),
    'weight' => -10,
  );

  $data['bpi_syndicated']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['bpi_syndicated']['nid'] = array(
    'title' => t('Nid'),
    'help' => t('Node id.'),
    'relationship' => array(
      'base' => 'node', // The name of the table to join with.
      'base field' => 'nid', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Default label for the relationship'),
      'title' => t('Title shown when adding the relationship'),
      'help' => t('More information on this relationship'),
    ),
    'field' => array(
      'handler' => 'views_handler_field_node',
      'click sortable' => TRUE,
    ),
  );

  $data['bpi_syndicated']['status'] = array(
    'title' => t('BPI status field and action'),
    'help' => t('Add bpi status as field in view.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'bpi_handler_bpistatus',
      'sortable' => TRUE,
    ),
  );

  return $data;
}

function bpi_views_data_alter(&$data) {
  $data['node']['bpi_syndicated'] = array(
    'title' => t('BPI status'),
    'help' => t('BPI reference.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'bpi_syndicated',
      'base field' => 'nid',
      'real field' => 'nid',
      'label' =>t('BPI reference'),
    ),
  );

  $data['node']['bpi_syndicated_status'] = array(
    'title' => t('BPI Node status'),
    'help' => t('Current node status in BPI.'),
    'real field' => 'nid',
    'field' => array(
      'handler' => 'bpi_handler_bpistatus',
    ),
  );
}
