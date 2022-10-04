//
// Created by Stéphane on 22.09.22.
//
#include "house.h"

string House::read_svg(int house) {
    string* h = new string[12];
    //h[0] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+MTwvdGV4dD48L3N2Zz4=";
    //h[1] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+MjwvdGV4dD48L3N2Zz4=";
    //h[2] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+MzwvdGV4dD48L3N2Zz4=";
    //h[3] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+NDwvdGV4dD48L3N2Zz4=";
    //h[4] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+NTwvdGV4dD48L3N2Zz4=";
    //h[5] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+NjwvdGV4dD48L3N2Zz4=";
    //h[6] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+NzwvdGV4dD48L3N2Zz4=";
    //h[7] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+ODwvdGV4dD48L3N2Zz4=";
    //h[8] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDYuNjYgMTMuMDQiPjxkZWZzPjxzdHlsZT4uY2xzLTF7aXNvbGF0aW9uOmlzb2xhdGU7Zm9udC1zaXplOjEycHg7ZmlsbDojMWQxZDFiO2ZvbnQtZmFtaWx5Ok15cmlhZFByby1Cb2xkLCBNeXJpYWQgUHJvO2ZvbnQtd2VpZ2h0OjcwMDt9PC9zdHlsZT48L2RlZnM+PHRleHQgY2xhc3M9ImNscy0xIiB0cmFuc2Zvcm09InRyYW5zbGF0ZSgwIDEwLjA0KSI+OTwvdGV4dD48L3N2Zz4=";
    //h[9] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDEzLjMyIDEzLjA0Ij48ZGVmcz48c3R5bGU+LmNscy0xe2lzb2xhdGlvbjppc29sYXRlO2ZvbnQtc2l6ZToxMnB4O2ZpbGw6IzFkMWQxYjtmb250LWZhbWlseTpNeXJpYWRQcm8tQm9sZCwgTXlyaWFkIFBybztmb250LXdlaWdodDo3MDA7fTwvc3R5bGU+PC9kZWZzPjx0ZXh0IGNsYXNzPSJjbHMtMSIgdHJhbnNmb3JtPSJ0cmFuc2xhdGUoMCAxMC4wNCkiPjEwPC90ZXh0Pjwvc3ZnPg==";
    //h[10] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDEzLjMyIDEzLjA0Ij48ZGVmcz48c3R5bGU+LmNscy0xe2lzb2xhdGlvbjppc29sYXRlO2ZvbnQtc2l6ZToxMnB4O2ZpbGw6IzFkMWQxYjtmb250LWZhbWlseTpNeXJpYWRQcm8tQm9sZCwgTXlyaWFkIFBybztmb250LXdlaWdodDo3MDA7fTwvc3R5bGU+PC9kZWZzPjx0ZXh0IGNsYXNzPSJjbHMtMSIgdHJhbnNmb3JtPSJ0cmFuc2xhdGUoMCAxMC4wNCkiPjExPC90ZXh0Pjwvc3ZnPg==";
    //h[11] = "PHN2ZyBpZD0iQ2FscXVlXzEiIGRhdGEtbmFtZT0iQ2FscXVlIDEiIHhtbG5zPSJodHRwOi8vd3d3LnczLm9yZy8yMDAwL3N2ZyIgdmlld0JveD0iMCAwIDEzLjMyIDEzLjA0Ij48ZGVmcz48c3R5bGU+LmNscy0xe2lzb2xhdGlvbjppc29sYXRlO2ZvbnQtc2l6ZToxMnB4O2ZpbGw6IzFkMWQxYjtmb250LWZhbWlseTpNeXJpYWRQcm8tQm9sZCwgTXlyaWFkIFBybztmb250LXdlaWdodDo3MDA7fTwvc3R5bGU+PC9kZWZzPjx0ZXh0IGNsYXNzPSJjbHMtMSIgdHJhbnNmb3JtPSJ0cmFuc2xhdGUoMCAxMC4wNCkiPjEyPC90ZXh0Pjwvc3ZnPg==";
    //return "data:image/svg+xml;base64," + h[house - 1];
    h[0] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAc0lEQVR4nK2OwQ1AQBBFZ1YD7oRRCZ3QAR1QghK0oKONzd4VIDvGRlxkScRLJpn8d3kID7xLIoqd22oA7pbFFjJ5UA6I0so5npghN8b67eB6siwdmbkNyUFk/7tMJgmqb1Jqy7OWEKNGKTVrrVcUF+S73AG6TD4OtGrRkgAAAABJRU5ErkJggg==";
    h[1] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAqklEQVR4nJ2OwQ3CMAxF7QTOdABahQ06QpmAFRiBDSgTwAgdpRtQNrCaDtB7acxPDxEXQOJdLPl9f5npC79lnudHZr2qasbMl74fagLsQAjPkzHchqANAhtr1zsBUWaYI4Gi2NaQ5ySxS0DeVKn0fqgIJOnQEMLUGbOuBBBIMl4Zs2pEpItBzHGR8VsiPTBTh3yG6of3vmHnXDnP053esJb3IkO7XH7if/kC6iNMDmtGEQwAAAAASUVORK5CYII=";
    h[2] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAt0lEQVR4nIWPwQ3CMAxFvy249w6NvAGwASOwAbABTEJH6AiMwCaEhp4ZoLThNxKFC+VJSRS/2F8RjPBf5nm+E4mnGGMmokVVhSPLECNd12xUp5e2bUoAixDq1JS2N87NC3avKZe8fqRzbgt0BUvlMJYrYTZft22kxALQfQihHGSPEeZeRXCsqroQM1sCz8z7+wWEuQ/VycoTcW52iBGn/gvMvKkqy+HMd0hjzSzjwW7v8UWSvxiVL87ySQ7PSHu6AAAAAElFTkSuQmCC";
    h[3] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAkUlEQVR4nJ2N0Q2CQAyG/4Pw7rtw6QbgBDqCo7iBjuAIjoIT4AiXVKeAUgsxREIghC/ppdcv/euwwHpJRIVIXTF/+nn/dBDRrm3rShU0kd6nN1U9W5uPpPf7SxQlpUhzB/Q4SIuzO1Iw8yPL0nIkf3FX6/9wT+b3qdskoLECRNRikcdxcgghvJx9BiaxVrNsl19S/EIOaKKQfgAAAABJRU5ErkJggg==";
    h[4] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAs0lEQVR4nIXP4Q2CMBAF4HeVARwASEdgBDdAN2AER8AR3AA3YAPrBMYJbFoG8L9SfDSGEGPwS5o2fb1eK1jwP9TU9887l5GIHJ3r9jHM87TGjFJJYymGWZaeRWCUwsXazuBDtNYFr7xiIma1SnYsfMRKTUDPQ0MFDCV7HtizFnxhi5YTvO+2wqJ1CKF0zp24xzCrQN77ZgyLEF6G1/Er0iolN2t9CxKOSOt0M3/paAp/WQzfxIxEDgd6eJoAAAAASUVORK5CYII=";
    h[5] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAuklEQVR4nI2OwRGCMBBFd4Pc8SyZSQmUQAnagSXQAVKCHdCCFTB0QAdmCN69YxJ/MugMHhjfJZt9f5Nl2uA/qZTKnLM1kWchdq3WeohSAefmznvRGGNaWohSyrzDxN6YR4HrF8aQsna+o+wRyJjJC5Ge8KyGzEtrfcfMTfhrCd6MmY4rOY7TRcqDh+whS8iw5UsTUQtZBYngNdSMJkkpz0SuIhI1ziZJ0lJr/Yzyg1KqQHNAGVnJXzblG8GFVg6iP3bFAAAAAElFTkSuQmCC";
    h[6] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAm0lEQVR4nIWOwQ3CMAxF7UrcuYMijxA2YATYJKMwQkcok8AGWDU903tJwycqkRCofZfv5MlfZpphWTq3faSU1hgn+Gx2P7CI+HEcmpRYCTCTxxzMrM5SVa804dzmVlWrHf76XPtBQIzPGpV7Al8SWwFBbdudED/ygsojKpVAkQJiHBqzzuOZKRJbAVEq3xQpuBqhoEdmivzHrHwBJW4+DhPJnpIAAAAASUVORK5CYII=";
    h[7] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAyElEQVR4nIWPwRGCMBBFd4ne9axhUoJ2ABWIFUAJliCd0IFQgXQAJWQI3LkzIX4Y5OTgn8ns5L/Nzy7Thv5D3z89nOMA15zIxULs7lrrnpVSF2uHSggPhsmlPJfMVDZN+1whM9Wetw/Hcaic81JjTPaNzZyjmJl7xBZN0yUEzVBKmcCMcG4ECcGh1m3JaokVYn8lssra8YU3hTFtBCijyQA8ThPiC000DdQlS+w84Rvr1ERjisZAo3GGk5RSBxTSMFFmrfCXNuEH+k5dDkjMJisAAAAASUVORK5CYII=";
    h[8] = "iVBORw0KGgoAAAANSUhEUgAAAAcAAAANCAYAAABlyXS1AAAAv0lEQVR4nIWPwRGCMBBFd8l49y7B2AElQAVSglbgWIFQiXagVCBWQAlmCAV4ZzbrktEZD4rv+F/+3wnCBP+l1nqDyCkzGES8d53bSwxojEmJhlYpzEEg4itAtHXOnTBJ4pKZD0phbm3faL1g6dTO9YU0dUHkz+/XL3kTmaEsgdZxIzeXEtayspO7Vdf1ZZAjRiCiDMAflZqtrPAp594PLXNUjfMgBClfWctsHkXYWOsuEgVwbFhrH/CF0PzFpHwCCmFVDrx3TRMAAAAASUVORK5CYII=";
    h[9] = "iVBORw0KGgoAAAANSUhEUgAAAA0AAAANCAYAAABy6+R8AAAAzElEQVR4nL2QzQ3CMBSD/VS4M0CDwgZsQLtJN4ANYISOwAgwAR2hI0RNe4YBSB7mR4CQOLRCfFIUJX6OIwsGMNxkrZ3EeF4COmuarsADY0whonNV2CQZbZxzNa8hVwMQshh1S7H2vs1ArE2zEPTgfSfTabqhtqCWU4Jw3TAmrUAoZCAcLFV1+TLpOknGM6a5r6b7Wfn6u0ly59rqtyYO9v/eZxFMLdisBRHL9kIICyDuROSkKoX3fg/C4ZLbkc3lrHzFkJpnPJP68D/TBW5blA7gKcNxAAAAAElFTkSuQmCC";
    h[10] = "iVBORw0KGgoAAAANSUhEUgAAAA0AAAANCAYAAABy6+R8AAAAnElEQVR4nN2QsQ3CQBAE9yyRO4eXnhKoAHeAqQB3QEm4BOgAOnAJLz/kFMDfsW8ZRIoDAiacvdVJK5jA9JL3vlR97AFb9v2twYgn9DszrGK81lQDQl8CqVK1lmHHsALx9CmlGtADzy4vnxk+ZZxbnEE+w4xzc+PZ/5fGldZc6SgidzNpYoyn7FV1Y5ZaEYSimG1DCB3I+9M3/K70BC5Kag7UlQcTAAAAAElFTkSuQmCC";
    h[11] = "iVBORw0KGgoAAAANSUhEUgAAAA0AAAANCAYAAABy6+R8AAAA1UlEQVR4nL2Q0REBMRRF77MK8E8yUYmoAB2sCuiEEpRAB6sCStgR/hUgeW4Mxpcd++HM7Ew2952Xlwha0F5yzvVSui0AHZ5OlxJPrDUr1bRkWVUU3XlNQCQLQPQp6UYVxxDOHsQYU4qknqp4NpuwdMdsCvI4KWPMoAJh4EEcm7HxlUtmfWVps/RJloqiM6vrsOVvs/Qc03/e9avkOGKMtw33pnn9GverZG3/AHQqPsSVj+SZjUEkd4gxjoC0FRGGUoYQdtYO1qq6wBvZU/Igwu9n/ifdARwYdA6KQjP/AAAAAElFTkSuQmCC";
    return "data:image/png;base64," + h[house - 1];
}

H House::init(int object_id, double longitude, Angles angle) {
    SplitDeg splig_deg = Swe17::split_deg(longitude, 0);
    H h;
    h.object_id = object_id;
    h.longitude = longitude;
    h.split = splig_deg;
    h.angle = angle;
    return h;
}

Image House::generer(int house, double x, double y, double width, double height) {
    return Image(Point(x, y), width, height, House::read_svg(house), Color::Black);
}
