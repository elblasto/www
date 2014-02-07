<?php

// Plugin definition
$plugin = array(
  'title' => t('Две колонки v1'),
  'category' => t('Bootstrap'),
  'icon' => 'two_col_v1.png',
  'theme' => 'two_col_v1',
  'css' => 'two_col_v1.css',
  'regions' => array(
    'body' => t('Основная колонка'),
    'right' => t('Правая колонка')
  ),
);
