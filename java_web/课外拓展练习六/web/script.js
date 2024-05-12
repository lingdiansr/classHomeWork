    const availableList = document.getElementById('available-list');
    const selectedList = document.getElementById('selected-list');
    const moveRightButton = document.getElementById('move-right');
    const moveLeftButton = document.getElementById('move-left');
    const selectedFruitsDisplay = document.getElementById('selected-fruits');

    // 点击可选项时切换选中状态并改变背景颜色
    availableList.addEventListener('click', function(e) {
        if (e.target.tagName === 'LI') {
            e.target.classList.toggle('selected');
        }
    });

    // 移动到已选项列表
    moveRightButton.addEventListener('click', function() {
        const selectedFruits = availableList.querySelectorAll('.selected');
        selectedFruits.forEach(fruit => {
            selectedList.appendChild(fruit);
            fruit.classList.remove('selected');
        });
        updateSelectedFruitsDisplay();
    });

    // 更新下方显示区域
    function updateSelectedFruitsDisplay() {
        selectedFruitsDisplay.innerHTML = ''; // 清空之前的内容
        const fruits = Array.from(selectedList.querySelectorAll('li'));
        fruits.forEach((fruit, index) => {
            const p = document.createElement('p');
            p.textContent = fruit.textContent;
            selectedFruitsDisplay.appendChild(p);
        });
    }

    // 从已选项列表移回可选项列表
    moveLeftButton.addEventListener('click', function() {
        const selectedFruits = selectedList.querySelectorAll('.selected');
        selectedFruits.forEach(fruit => {
            availableList.appendChild(fruit);
            fruit.classList.remove('selected');
        });
        updateSelectedFruitsDisplay();
    });

    // 点击已选项时切换选中状态并改变背景颜色
    selectedList.addEventListener('click', function(e) {
        if (e.target.tagName === 'LI') {
            e.target.classList.toggle('selected');
        }
    });




