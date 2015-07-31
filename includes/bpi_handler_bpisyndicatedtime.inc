<?php
/**
 * @file
 *  Definition of bpi_handler_bpisyndicatedtime
 */

class bpi_handler_bpisyndicatedtime extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['bpi'] = array(
      'table' => 'bpi_syndicated',
      'field' => 'timestamp',
    );
  }

  /**
   * {@inheritdoc}
   *
   * Perform any database or cache data retrieval here. In this example there is
   * none.
   */
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  /**
   * {@inheritdoc}
   *
   * Modify any end user views settings here. Debug $options to view the field
   * settings you can change.
   */
  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }


  /**
   * Called to determine what to tell the clicksorter.
   */
  function click_sort($order) {
    if (isset($this->field_alias)) {
      // Since fields should always have themselves already added, just
      // add a sort on the field.
      $params = $this->options['group_type'] != 'group' ? array('function' => $this->options['group_type']) : array();
      $this->query->add_orderby(NULL, NULL, $order, $this->field_alias, $params);
    }
  }

  /**
   * Determine if this field is click sortable.
   */
  function click_sortable() {
    echo "<pre>";
    print_r(1);
    die();
    return !empty($this->definition['click sortable']);
  }

  /**
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    $syndicated = '';
    $bpi_mapped_ct = variable_get('bpi_content_type', FALSE);
    if ($values->node_type == $bpi_mapped_ct) {
        $syndicated = '<p>' . date('d/m/Y H:i', $values->bpi_syndicated_timestamp) . '</p>';
    }

    return $syndicated;
  }
}
