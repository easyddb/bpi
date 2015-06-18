<?php
/**
 * @file
 *  Definition of bpi_handler_bpistatus
 */

class bpi_handler_bpistatus extends views_handler_field {

  function construct() {
    parent::construct();
    $this->additional_fields['bpi'] = array(
      'table' => 'bpi_syndicated',
      'field' => 'status',
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
   * Render callback handler.
   *
   * Return the markup that will appear in the rendered field.
   */
  function render($values) {
    $status_action = '';
    $bpi_mapped_ct = variable_get('bpi_content_type', FALSE);
    $bpi_statuses = array(
      BPI_SYNDICATED => t('Syndicated'),
      BPI_PUSHED => t('Pushed'),
    );

    if ($values->node_type == $bpi_mapped_ct) {
      $status_action = l(t('Push to BPI'), 'admin/bpi/push/nojs/' . $values->nid);
      if (!empty($values->bpi_syndicated_status)) {
        $status_action = '<p>' . $bpi_statuses[$values->bpi_syndicated_status] . '</p>';
      }
    }

    return $status_action;
  }
}
