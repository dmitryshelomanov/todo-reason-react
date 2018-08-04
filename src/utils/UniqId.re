let id = ref(0);

let getUniqId = () => {
  id := id^ + 1;

  id^
};
