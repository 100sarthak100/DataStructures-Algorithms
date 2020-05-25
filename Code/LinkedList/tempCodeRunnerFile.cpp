Node *temp = node->next;
    *node = *(node->next);
    delete temp;