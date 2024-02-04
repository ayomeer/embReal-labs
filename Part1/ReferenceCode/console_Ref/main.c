/* USER CODE BEGIN 0 */
// Re-implementation of __weak _write function (has to be compiled w/ C-compiler!
int _write(int file, char *ptr, int len){
  (void)file;

  HAL_UART_Transmit(&huart3, (uint8_t*)ptr++, len, 10);
  return len;
}
/* USER CODE END 0 */