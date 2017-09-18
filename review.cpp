template <class ItemType>
bool ArrayBag<ItemType>::add (const ItemType& newEntry) {
  bool hasRoomToAdd = (itemCount < maxItem);

  if(hasRoomToAdd) {
    item [itemCount] = newEntry;
    itemCount++;

  }
  return hasRoomToAdd;
}
