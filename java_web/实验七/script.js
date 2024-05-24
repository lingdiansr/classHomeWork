//获取或设置一个元素内部的HTML内容
const loadDataBtn = document.getElementById('loadDataBtn');
const searchBox = document.getElementById('searchBox');
const searchInput = document.getElementById('searchInput');
const movieTable = document.getElementById('movieTable');
const backgroundRectangle = document.querySelector('.background-rectangle');
const movieTableBody = document.getElementById('movieTableBody');
let moviesData = [];
let sortedmovies = [];
let searchTerm;
loadDataBtn.addEventListener('click', clickLoadData)//第一个参数是事件名称，第二个参数是调用函数

function clickLoadData() {
    fetch('./movies.json')
        .then(response => response.json())//将response解析为json格式
        .then(data => {//由.json解析出的数据对象data，将movies.json文件中的数据解析出来存入moviesData数组中，再调用showTable方法
            moviesData = data;
            showTable();
        })
        .catch(error => console.error(error));

}

function showTable() {
    loadDataBtn.style.display = 'none';
    searchBox.style.display = 'block';
    movieTable.style.display = 'table';
    backgroundRectangle.style.display = 'block';
    updatetable(moviesData);
}

function updatetable(sortedmovies, searchTerm) {
    // var length = movieTableBody.firstChild.childNodes.length;
    // 删除所有行列及其内容，置空
    movieTableBody.innerHTML = '';

    if (sortedmovies.length > 0) {//如果有匹配的书籍，数组长度大于0，进入循坏
        for (let i = 0; i < sortedmovies.length; i++) {//按原本新数组降序存入的书籍，重新插入新的行和单元格
            let row = movieTableBody.insertRow();
            let cell1 = row.insertCell(0);
            let cell2 = row.insertCell(1);
            let cell3 = row.insertCell(2);
            let cell4 = row.insertCell(3);
            let cell5 = row.insertCell(4);
            let cell6 = row.insertCell(5);

            cell1.textContent = i + 1;
            cell2.innerHTML = highlightMatch(sortedmovies[i].title, searchTerm);
            cell3.innerHTML = highlightMatch(sortedmovies[i].director, searchTerm);
            cell4.innerHTML = highlightMatch(sortedmovies[i].cast, searchTerm);
            cell5.innerHTML = highlightMatch(sortedmovies[i].release_date, searchTerm);
            cell6.innerHTML = highlightMatch(sortedmovies[i].genre, searchTerm);
        }
    } else {
        // 如果没有匹配到结果，则显示“无”
        let noResultRow = movieTableBody.insertRow();
        let noResultCell = noResultRow.insertCell(0);
        noResultCell.colSpan = 6; // 合并三列显示“无”
        noResultCell.textContent = "无";
    }
}

function searchmovies() {
    searchTerm = searchInput.value.trim();
    if (searchTerm != "") {
        //获取输入元素的值，将其转换为小写，并删除空格换行符号
        // 按照字符匹配个数从多到少排序
        sortedmovies = moviesData.filter(movie => {//返回一个新数组，符合要求的新数组
            let matchCount = 0;
            searchTerm.split('').forEach(char => {
                if (movie.title.includes(char)
                    || movie.director.includes(char)
                    || movie.cast.includes(char)) {//遍历书名全部转换为小写看是否有与输入的字符匹配的字符，有则匹配度+1
                    matchCount++;
                }
            });
            movie.matchCount = matchCount;//将匹配度给每部电影
            return matchCount > 0;//有匹配的值才会将数据降序存入新的数组，如果没有数组为空
        }).sort((a, b) => b.matchCount - a.matchCount);    //降序
        updatetable(sortedmovies, searchTerm);
    } else {
        updatetable(moviesData);
    }
}

function highlightMatch(text, searchTerm) {
    let regex = new RegExp(`[${searchTerm}]`, 'ig');
    /**'i' 标志表示不区分大小写的匹配（忽略大小写）。
     'g' 标志表示全局搜索，即匹配整个输入字符串中的所有实例，而不仅仅是第一个出现。 */
    let highlightedText = text.replace(regex, (match) => {
        return `<span class="match-highlight">${match}</span>`;
    });
    return highlightedText;
}

function sortmovies() {
    var cmp = (a, b) => b.release_date.localeCompare(a.release_date);
    if (searchTerm != undefined) {
        updatetable(sortedmovies.sort(cmp), searchTerm);
    } else {
        updatetable(moviesData.sort(cmp));
    }
}